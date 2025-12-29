#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem> // Requires C++17

// Alias for the filesystem namespace for convenience
namespace fs = std::filesystem;

/**
 * @brief Removes trailing whitespace (spaces and tabs) from a string.
 * @param s The string to modify in-place.
 */
void trim_trailing_whitespace(std::string& s) {
    size_t last = s.find_last_not_of(" \t");
    if (std::string::npos != last) {
        s.erase(last + 1);
    } else {
        // If the string is empty or contains only whitespace, clear it.
        s.clear();
    }
}

/**
 * @brief Processes a single file: trims trailing whitespace from each line
 *        and ensures a final newline at the end of the file.
 * @param file_path The path to the file to process.
 */
void process_file(const fs::path& file_path) {
    std::cout << "Processing: " << file_path.filename().string() << " ... ";

    // 1. Open and read all lines into a vector.
    std::ifstream infile(file_path);
    if (!infile.is_open()) {
        std::cerr << "\nError: Could not open file for reading: " << file_path << std::endl;
        return;
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(infile, line)) {
        lines.push_back(line);
    }
    infile.close();
    
    // An empty file doesn't need a final newline, just truncate it.
    if (lines.empty()) {
        // Re-open with truncation to ensure it's an empty file.
        std::ofstream outfile(file_path, std::ios::trunc);
        outfile.close();
        std::cout << "File is empty. Skipped." << std::endl;
        return;
    }

    // 2. Process each line in the vector.
    for (std::string& current_line : lines) {
        trim_trailing_whitespace(current_line);
    }

    // 3. Open the file in truncation mode to overwrite it.
    std::ofstream outfile(file_path, std::ios::trunc);
    if (!outfile.is_open()) {
        std::cerr << "\nError: Could not open file for writing: " << file_path << std::endl;
        return;
    }

    // 4. Write all processed lines back, adding a newline after each one.
    // This simple loop naturally handles the final newline requirement.
    for (const std::string& processed_line : lines) {
        outfile << processed_line << '\n';
    }
    outfile.close();

    std::cout << "Done." << std::endl;
}

int main() {
    try {
        const fs::path current_dir = fs::current_path();
        std::cout << "Scanning directory: " << current_dir.string() << std::endl;

        bool found_files = false;

        // Iterate over all entries in the current directory.
        for (const auto& entry : fs::directory_iterator(current_dir)) {
            // Check if it's a regular file with a ".in" extension.
            if (entry.is_regular_file() && entry.path().extension() == ".in") {
                found_files = true;
                process_file(entry.path());
            }
        }

        if (!found_files) {
            std::cout << "No .in files found in the current directory." << std::endl;
        }

    } catch (const fs::filesystem_error& e) {
        std::cerr << "Filesystem Error: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}