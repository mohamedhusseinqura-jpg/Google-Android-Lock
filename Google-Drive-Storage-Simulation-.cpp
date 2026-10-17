#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct DriveFile {
    string name;
    double sizeMB;
};

class GoogleDrive {
private:
    vector<DriveFile> files;
    const double maxStorage = 15.0 * 1024; // 15 GB inside MB
    double usedStorage = 0;

public:
    void uploadFile(string name, double size) {
        if (usedStorage + size > maxStorage) {
            cout << "Upload Failed! Google Drive storage is full." << endl;
            return;
        }
        files.push_back({name, size});
        usedStorage += size;
        cout << "Successfully uploaded: " << name << " (" << size << " MB)" << endl;
    }

    void showStorageInfo() {
        cout << "\n--- Google Drive Storage ---" << endl;
        cout << "Used: " << usedStorage << " MB / " << maxStorage << " MB" << endl;
        cout << "Files count: " << files.size() << endl;
    }
};

int main() {
    GoogleDrive myDrive;
    myDrive.uploadFile("Project_Backup.zip", 450.5);
    myDrive.uploadFile("Vacation_Video.mp4", 1200.0);
    myDrive.showStorageInfo();
    return 0;
}
