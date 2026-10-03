#include "FileManager.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

FileManager::FileManager() {}
FileManager::~FileManager() {}

bool FileManager::saveLines(const string &filename,
                            const vector<string> &lines) const {
    ofstream out(filename);              // opens file for writing
    if (!out.is_open())
        throw runtime_error("Cannot open file for writing: " + filename);
    for (const string &line : lines)
        out << line << "\n";
    out.close();
    return true;
}

vector<string> FileManager::loadLines(const string &filename) const {
    vector<string> lines;
    ifstream in(filename);               // opens file for reading
    if (!in.is_open())
        return lines;                    // first run: no file yet, that's fine
    string line;
    while (getline(in, line)) {
        if (!line.empty())
            lines.push_back(line);
    }
    in.close();
    return lines;
}

vector<string> FileManager::split(const string &line, char delimiter) const {
    vector<string> parts;
    stringstream ss(line);
    string part;
    while (getline(ss, part, delimiter))
        parts.push_back(part);
    return parts;
}
