#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <map>
#include <set>
#include <stdexcept>
#include <algorithm>
#include <numeric>

// For convenience, we use a shorthand for the filesystem namespace
namespace fs = std::filesystem;

// An enum to represent the special graph properties
enum class Property { NONE, CHAIN, STAR, MAX_CHILDREN_100 };

// A struct to hold the constraints for each test bundle
struct BundleConstraints {
    int max_n_m;
    Property property;
};

// A map to store the constraints for all test bundles
const std::map<int, BundleConstraints> constraints = {
    {1,  {100,         Property::NONE}},
    {2,  {700,         Property::NONE}},
    {3,  {2000,        Property::NONE}},
    {4,  {4000,        Property::NONE}},
    {5,  {50000,       Property::NONE}},
    {6,  {100000,      Property::NONE}},
    {7,  {200000,      Property::CHAIN}},
    {8,  {200000,      Property::STAR}},
    {9,  {200000,      Property::MAX_CHILDREN_100}}, // Updated property
    {10, {200000,      Property::NONE}},
    {11, {200000,      Property::NONE}},
    {12, {200000,      Property::NONE}},
    {13, {200000,      Property::NONE}},
};

// Simple DSU implementation for cycle detection
struct DSU {
    std::vector<int> parent;
    DSU(int n) { parent.resize(n + 1); std::iota(parent.begin(), parent.end(), 0); }
    int find(int i) { return (parent[i] == i) ? i : (parent[i] = find(parent[i])); }
    void unite(int i, int j) { parent[find(i)] = find(j); }
};

// A helper function to report failure and exit
void fail(const std::string& message) {
    std::cerr << "\n[VALIDATION FAILED] " << message << std::endl;
    exit(1);
}

// The core validation logic function
void validate_file(const fs::path& file_path) {
    std::cout << "Checking file: " << file_path.string() << " ... " << std::flush;

    // 1. Parse the bundle ID from the filename
    std::string filename = file_path.filename().string();
    int bundle_id = -1;
    try {
        const std::string prefix = "rplexq";
        size_t prefix_pos = filename.find(prefix);
        size_t underscore_pos = filename.find('_');
        if (prefix_pos != 0 || underscore_pos == std::string::npos) {
            underscore_pos = filename.find('.'); // Fallback for names like rplexq2.in
            if (underscore_pos == std::string::npos) throw std::invalid_argument("Invalid filename format.");
        }
        std::string num_str = filename.substr(prefix.length(), underscore_pos - prefix.length());
        bundle_id = std::stoi(num_str);
    } catch (const std::exception& e) {
        fail("Could not parse bundle ID from filename: " + filename);
    }

    if (constraints.find(bundle_id) == constraints.end()) {
        fail("Unknown bundle ID: " + std::to_string(bundle_id) + " for file " + filename);
    }
    const auto& current_constraints = constraints.at(bundle_id);

    // 2. Open and read the file
    std::ifstream in_file(file_path);
    if (!in_file.is_open()) fail("Could not open file: " + file_path.string());

    int n, m, root;
    if (!(in_file >> n >> m >> root)) fail("Failed to read n, m, root.");

    // Check n, m, root against constraints
    if (n < 1 || n > 200000 || m < 1 || m > 200000) fail("n or m is out of global range [1, 200000].");
    if (n > current_constraints.max_n_m) fail("n=" + std::to_string(n) + " violates bundle constraint (max " + std::to_string(current_constraints.max_n_m) + ").");
    if (m > current_constraints.max_n_m) fail("m=" + std::to_string(m) + " violates bundle constraint (max " + std::to_string(current_constraints.max_n_m) + ").");
    if (root < 1 || root > n) fail("root=" + std::to_string(root) + " is out of range [1, n].");

    // Check tree structure and properties
    DSU dsu(n);
    std::vector<int> degree(n + 1, 0);
    std::set<std::pair<int, int>> edges_seen;
    if (n > 1) {
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            if (!(in_file >> u >> v)) fail("Failed to read edge #" + std::to_string(i + 1));
            if (u < 1 || u > n || v < 1 || v > n) fail("Edge endpoint out of range [1, n] for edge #" + std::to_string(i + 1));
            if (u == v) fail("Self-loop found on node " + std::to_string(u));

            if (u > v) std::swap(u, v);
            if (edges_seen.count({u, v})) fail("Multiple edges between " + std::to_string(u) + " and " + std::to_string(v));
            edges_seen.insert({u, v});

            if (dsu.find(u) == dsu.find(v)) fail("Cycle detected involving edge (" + std::to_string(u) + ", " + std::to_string(v) + ")");
            dsu.unite(u, v);
            
            degree[u]++;
            degree[v]++;
        }
    }

    // Verify special properties
    if (current_constraints.property == Property::CHAIN) {
        if (n > 2) {
            int degree_one_count = 0, degree_two_count = 0;
            for (int i = 1; i <= n; ++i) {
                if (degree[i] == 1) degree_one_count++;
                else if (degree[i] == 2) degree_two_count++;
            }
            if (degree_one_count != 2 || degree_two_count != n - 2) fail("Graph does not form a chain.");
        }
    } else if (current_constraints.property == Property::STAR) {
        if (n > 2) {
            int center_count = 0, leaf_count = 0;
            for (int i = 1; i <= n; ++i) {
                if (degree[i] == n - 1) center_count++;
                else if (degree[i] == 1) leaf_count++;
            }
            if (center_count != 1 || leaf_count != n - 1) fail("Graph does not form a star (chrysanthemum).");
        }
    } else if (current_constraints.property == Property::MAX_CHILDREN_100) {
        for (int i = 1; i <= n; ++i) {
            // Calculate number of children based on degree and root status
            int children_count = (i == root) ? degree[i] : (degree[i] - 1);
            if (children_count < 0) children_count = 0; // For leaf nodes
            if (children_count > 100) {
                fail("Node " + std::to_string(i) + " has " + std::to_string(children_count) + " children, violating max children 100 property.");
            }
        }
    }
    
    // Check queries
    for (int i = 0; i < m; ++i) {
        int l, r, x;
        if (!(in_file >> l >> r >> x)) fail("Failed to read query #" + std::to_string(i+1));
        if (l < 1 || l > r || r > n) fail("Query #" + std::to_string(i+1) + " violates 1 <= l <= r <= n. Got l=" + std::to_string(l) + ", r=" + std::to_string(r) + ", n=" + std::to_string(n));
        if (x < 1 || x > n) fail("Query #" + std::to_string(i+1) + " violates 1 <= x <= n. Got x=" + std::to_string(x) + ", n=" + std::to_string(n));
    }

    // Check for trailing characters
    char extra;
    if (in_file >> extra) fail("Extra content found at the end of the file.");

    std::cout << "[OK]" << std::endl;
}

int main(int argc, char* argv[]) {
    std::cout << "Note: Compiling with -std=c++17 is required for <filesystem>." << std::endl;
    
    // Determine the directory to scan
    fs::path scan_dir = "."; // Default to the current directory
    if (argc > 1) scan_dir = argv[1];

    if (!fs::exists(scan_dir) || !fs::is_directory(scan_dir)) {
        std::cerr << "Error: Directory '" << scan_dir.string() << "' does not exist or is not a directory." << std::endl;
        return 1;
    }

    std::cout << "Starting validation in directory: " << scan_dir.string() << std::endl;
    
    std::vector<fs::path> files_to_check;
    try {
        for (const auto& entry : fs::directory_iterator(scan_dir)) {
            if (entry.is_regular_file() && entry.path().extension() == ".in") {
                if (entry.path().filename().string().rfind("rplexq", 0) == 0) {
                    files_to_check.push_back(entry.path());
                }
            }
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
        return 1;
    }

    if (files_to_check.empty()) {
        std::cout << "No 'rplexq*.in' files found to validate." << std::endl;
        return 0;
    }

    std::sort(files_to_check.begin(), files_to_check.end());

    for (const auto& file_path : files_to_check) {
        validate_file(file_path);
    }
    
    std::cout << "\nValidation finished for all " << files_to_check.size() << " files." << std::endl;
    return 0;
}