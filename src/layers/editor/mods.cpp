#include "./mods.hpp"

void EditorMods::buildHelper(CCLayer *)
{
    reinterpret_cast<void(__thiscall *)(EditorUI *, bool)>(base + 0x8ad10)(GameManager::sharedState()->getEditorLayer()->m_editorUI, false);
};

void EditorMods::prevMode(CCLayer *)
{
    GameManager::sharedState()->setGameVariable("0036", !GameManager::sharedState()->getGameVariable("0036"));
    reinterpret_cast<void(__thiscall *)(LevelEditorLayer *)>(base + 0x1652b0)(GameManager::sharedState()->getEditorLayer());
};