
#include <iostream>
#include <fstream>
#include <filesystem>


// check the file
// if the file suffix is config
bool isConfigFile(string p) {
    if (p.substr(p.find_last_of(".") + 1) == "config")
        return true;
    else
        return false;
}

// list all files and directories under specific directory recursivly
// path: path to the root directory
// p: a vector holds all items needed
int extractPaths(string path, vector<string> & p) {
    int result = 0;
    for (const auto & entry : fs::recursive_directory_iterator(path)) {
        if (entry.is_directory() == 0 && isConfigFile(entry.path())) {
            p.push_back(entry.path());
            result++;
        }
    }
    return result;

}

// replace specific strings in file with new string.
// path: path to the file
// toReplace: strings in file to be replaced
// replace: new string for the file
void myReplace(string path, string toReplace, string replace) {
    // open file for reading
    ifstream ist {path};
    if (!ist) {
        std::cerr << "Failed to open: " << path << endl;
        return;
    }
    
    string tmppath = path + "_tmp";
    // open file for writing
    ofstream ost {tmppath};
    if (!ost) {
        std::cerr << "Failed to create: " << tmppath << endl;
        return;
    }
    
    bool found = false;
    string line;
    while (getline(ist, line)) { // read one line a time 
        while (true) {
            size_t pos = line.find(toReplace);
            if (pos != string::npos) {
                line.replace(pos, string(toReplace).length(), replace);
                found = true;
            } else break;
        }
        ost << line;
    }
    ist.close();
    ost.close();
    
    if (found) {
        fs::rename(path, (path + "_bak"));
        fs::rename(tmppath, path);
    } else {
        fs::remove(tmppath);
    }
}
