#include "includes.h"

void inject() {
	static char pathh[MAX_PATH + 1];
	if (SHGetSpecialFolderPathA(HWND_DESKTOP, pathh, CSIDL_DESKTOP, TRUE)) {
		std::string  path = std::string(pathh).append(("\\WinApi.dll"));
		const char* dllPath = path.c_str();
		DWORD procId; HWND windowfm = FindWindowA(("grcWindow"), 0);
		GetWindowThreadProcessId(windowfm, &procId);
		HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, 0, procId);
		if (hProc && hProc != INVALID_HANDLE_VALUE) {
			void* loc = VirtualAllocEx(hProc, 0, MAX_PATH, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
			WriteProcessMemory(hProc, loc, dllPath, strlen(dllPath) + 1, 0);
			HANDLE hThread = CreateRemoteThread(hProc, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibraryA, loc, 0, 0);
			if (hThread) CloseHandle(hThread);
		}
		if (hProc) CloseHandle(hProc);
	}
}

