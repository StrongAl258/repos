//Alvin T Strong, 30 June 2020
// Implement post order tree-traversal to compute the size of file system using my own directory structure.
#include <iostream>
#include <filesystem>
using namespace std;

int diskSpace(const filesystem::path& directory) { // function to traverse the file system, directory gives access to windows path
	int s = 0;										// variable to hold total size of files
	for (const auto& entry : filesystem::recursive_directory_iterator(directory))   // entry used to represent whatever format the file name will be
	{																	// start the iterator at the directory and work up
		if (entry.is_regular_file() && !entry.is_symlink())				// if this a regular file and not a symbolic link then continue
		{
			s += entry.file_size();											// adds s to s and the file size
			filesystem::path file = entry.path();							// gives the name of the file
			cout << file.filename() << ": "<< entry.file_size() << endl;	// outputs the name of the file and size
		}
	}
	return s;
}
int main() {
	cout << diskSpace("c:") << endl;

	return 0;
}