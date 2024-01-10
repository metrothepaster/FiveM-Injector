#include "includes.h"
#include "inject.h"
#include "download.h"

int main()
{
	std::cout << "FiveM DLL Injector\nWritten by metro, discord.gg/coders\n\n\n";
	downloaddll();
	std::cout << "[/] WAITING FOR FIVEM...\n";
	while (!FindWindowA(("grcWindow"), 0));
	std::cout << "[/] FIVEM DETECTED, CLICK ANY BUTTON TO INJECT!\n";
	system("pause >nul");
	inject();
	std::cout << "[/] INJECTED";
	system("pause >nul");
}