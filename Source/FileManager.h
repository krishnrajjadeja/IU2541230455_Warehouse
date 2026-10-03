#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <string>
#include <vector>
using namespace std;

class FileManager {
public:
    FileManager();
    ~FileManager();

    // Write all lines to a file (overwrites old content)
    bool saveLines(const string &filename, const vector<string> &lines) const;

    // Read all lines from a file (empty list if file missing)
    vector<string> loadLines(const string &filename) const;

    // Split "1|Laptop|Electronics|55000" into separate parts
    vector<string> split(const string &line, char delimiter) const;
};
#endif
