#include "./main.hpp"

void mod_main(HMODULE)
{
    matdash::add_hook<&LayerInit::main>(base + 0x1907B0);
    matdash::add_hook<&LayerInit::editorUI>(base + 0x76310);

    matdash::add_hook<&LayerInit::GJGameLevelEditor>(base + 0x6F5D0);

    matdash::add_hook<&LayerInit::selectedLiveOverlay>(base + 0x41DB0);
    matdash::add_hook<&LayerInit::onSelectedTabLiveOverlay>(base + 0x430f0);

    matdash::add_hook<&LayerInit::pause>(base + 0x1E4620);

    matdash::add_hook<&LayerInit::play>(base + 0x1FB780);
    matdash::add_hook<&LayerInit::playUpdate>(base + 0x2029C0);

    // matdash::add_hook<&LayerInit::gameObjectCreateWithkey>(base + 0xcfac0);
};
