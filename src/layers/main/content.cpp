#include "./content.hpp"
#include "./../asa_player2_icon/content.hpp"

bool isFirsttime = true;

void MainLayerInit::init(CCLayer *self)
{
    if (isFirsttime)
    {
        // Cube
        WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void *>(base + 0x1f7e48), "\xB9\xFF\xFF", 3, NULL);
        WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void *>(base + 0x12C766), "\xC7\x44\x24\x14\xFF\xFF\x00\x00", 8, NULL);
        // Ship
        WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void *>(base + 0x1f7ff6), "\xBA\xFF\xFF", 3, NULL);
        WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void *>(base + 0x12C6D1), "\xC7\x44\x24\x14\xFF\xFF\x00\x00", 8, NULL);
        // Ball
        WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void *>(base + 0x1f83a6), "\xBA\xFF\xFF", 3, NULL);
        WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void *>(base + 0x12C6EC), "\xC7\x44\x24\x14\xFF\xFF\x00\x00", 8, NULL);
        // UFO
        WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void *>(base + 0x1f81a6), "\xBA\xFF\xFF", 3, NULL);
        WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void *>(base + 0x12C704), "\xC7\x44\x24\x14\xFF\xFF\x00\x00", 8, NULL);
        // Wave
        WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void *>(base + 0x1F8586), "\xBA\xFF\xFF", 3, NULL);
        WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void *>(base + 0x12C71C), "\xC7\x44\x24\x14\xFF\xFF\x00\x00", 8, NULL);
        // Robot
        WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void *>(base + 0x14673D), "\xB8\xFF\xFF", 3, NULL);
        WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void *>(base + 0x12C734), "\xC7\x44\x24\x14\xFF\xFF\x00\x00", 8, NULL);
        // Spider
        WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void *>(base + 0x146745), "\xBA\xFF\xFF", 3, NULL);
        WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void *>(base + 0x12C74C), "\xC7\x44\x24\x14\xFF\xFF\x00\x00", 8, NULL);

        isFirsttime = false;
    }
    SecondPlayer::setupMaxIcon();
    SecondPlayer::fixCrashIssue();
    MainMenuMods::customBackground(self);
    MainMenuMods::secondPlayerSelectedIcon(self);
};