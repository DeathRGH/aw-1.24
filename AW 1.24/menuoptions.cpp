#include "menuoptions.h"

#include "defines.h"

NAMESPACE(Menu)

Options_t Options;

void Init() {
	Options.menuOpen = false;
	Options.isInSubMenu = false;
	Options.menuMaxScroll = 0;
	Options.menuScroll = 0;
	Options.menuPageIndex = 0;
	Options.menuTabHeight = 75;
	Options.menuOptionIndex = 0;

	SetupColor(&Options.color_menuBorder, 0.0f, 0.4f, 1.0f, 1.0f, 0.2f);
	SetupColor(&Options.color_menuScroller, 0.0f, 0.48f, 0.8f, 1.0f, 0.2f);
	SetupColor(&Options.color_menuBackground, 0.18f, 0.18f, 0.19f, 0.95f, 0.2f);
	SetupColor(&Options.color_menuText, 1.0f, 1.0f, 1.0f, 1.0f, 0.2f);
	SetupColor(&Options.color_menuToggle, 0.0f, 0.48f, 0.8f, 1.0f, 0.2f);
	SetupColor(&Options.color_menuControlBackground, 0.12f, 0.12f, 0.12f, 1.0f, 0.2f);

	SetupInt(&Options.menuX, 45, 45, 3840, 0);
	SetupInt(&Options.menuY, 630, 630, 2160, 0);
	SetupInt(&Options.menuWidth, 1000, 1000, 4000, 0);
	SetupInt(&Options.menuHeight, 1200, 1200, 3000, 0);
	SetupInt(&Options.menuBorder, 0, 0, 20, 0);
	SetupInt(&Options.menuFontIndex, 2, 2, NUM_FONTS, 0);
	SetupFloat(&Options.menuFontSize, 0.75f, 0.75f, 2.0f, 0.01f, 0.001f);
	SetupInt(&Options.menuScrollerDelay, 50, 50, 500, 10);

	SetupInt(&Options.boxSize, 35, 35, 100, 5);
	SetupInt(&Options.sliderWidth, 100, 100, 200, 20);
	SetupInt(&Options.sliderHeight, 15, 15, 50, 4);

	SetupBool(&Options.debug_godmode, true);
	SetupBool(&Options.debug_infAmmo, true);
	SetupBool(&Options.debug_drawInfo, true);
	SetupBool(&Options.debug_test2, false);
	SetupBool(&Options.debug_testDisabled, true, false);
}

END
