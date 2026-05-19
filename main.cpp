// Process Viewer - By: Leeyiers

#include <windows.h>
#include <tlhelp32.h>
#include <iostream>
#include <iomanip>

using namespace std;

void ListProcesses() {
    HANDLE hProcessSnap;
    PROCESSENTRY32 pe32;

    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (hProcessSnap == INVALID_HANDLE_VALUE) {
        cout << "Failed to create process snapshot." << endl;
        return;
    }

    pe32.dwSize = sizeof(PROCESSENTRY32);

    if (!Process32First(hProcessSnap, &pe32)) {
        cout << "Failed to get process information." << endl;
        CloseHandle(hProcessSnap);
        return;
    }

    cout << left
         << setw(10) << "PID"
         << setw(35) << "Process Name"
         << endl;

    cout << "==================================================" << endl;

    do {

        cout << left
             << setw(10) << pe32.th32ProcessID
             << setw(35) << pe32.szExeFile
             << endl;

    } while (Process32Next(hProcessSnap, &pe32));

    CloseHandle(hProcessSnap);
}

int main() {

    SetConsoleTitleA("Process Viewer - By: Leeyiers");

    cout << "==========================================" << endl;
    cout << "         Process Viewer" << endl;
    cout << "          By: Leeyiers" << endl;
    cout << "==========================================" << endl;
    cout << endl;

    ListProcesses();

    cout << endl;
    system("pause");

    return 0;
}