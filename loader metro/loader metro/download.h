#include "includes.h"
#include "dllpath.h"

void downloaddll() {
	static char pathh[MAX_PATH + 1];
	if (SHGetSpecialFolderPathA(HWND_DESKTOP, pathh, CSIDL_DESKTOP, TRUE)) {
		std::string  path = std::string(pathh).append(("\\WinApi.dll"));
		static char pathh[MAX_PATH + 1];
		std::string temp_pathdll_1 = std::string(pathh).append(("\\WinApi.dll"));
		std::wstring temp_pathdll_2 = std::wstring(temp_pathdll_1.begin(), temp_pathdll_1.end());
		LPCWSTR finallydllpath = temp_pathdll_2.c_str();
		HRESULT hr = URLDownloadToFile(NULL, url, finallydllpath, 0, NULL);
		if (SUCCEEDED(hr)) std::cout << "[/] DLL DOWNLOADED FROM SERVER\n";
		else std::cout << "[X] ERROR WITH DLL DOWNLOAD\n";
	}
}
