/******************************************************/
/* Font Engine Configuration Library Demo Application */
/* Autor: Robert Henschel                             */
/* created : 27.12.2005                               */
/* modified: 05.01.2005                               */

#include <os2.h>
#include <stdio.h>
#include <stdlib.h>
#include "feconfig.h"


int main(int argc, char *argv[]) {

	int feInstalled, enabled;
	int rc, rc1, i;
	PCHAR name;

	/* you must call the "detectFontEngine() method first! */
	/* it initializes some internal values of the DLL      */
	feInstalled = detectFontEngine();
	if (feInstalled == ERROR_FONT_ENGINE_NOT_INSTALLED) {
		printf("\nFont Engine not installed!\n   You need to install the Font Engine before you can run this utility.\n");
		return 0;
	}

	printf("Font Engine detected.\n");

	enabled = isFontEngineEnabled();
	if (enabled == 1)
		printf("Font Engine is enabled.\n");
	else
		if (enabled == 0)
			printf("Warning: Font Engine is disabled!\n");
		else
			printf("!!!ERROR!!! (during isFontEngineEnabled)\n");

	printf("\nDisabling Font Engine.\n");
	rc = disableFontEngine();
	if (!rc)
		printf("  -> disabled\n");
	else
		printf("  -> ERROR!\n");

	enabled = isFontEngineEnabled();
	if (enabled == 1)
		printf("\nFont Engine is enabled.\n");
	else
		if (enabled == 0)
			printf("\nFont Engine is disabled.\n");
		else
			printf("\n!!!ERROR!!! (during isFontEngineEnabled)\n");

	printf("\nEnabling Font Engine.\n");
	rc = enableFontEngine();
	if (!rc)
		printf("  -> enabled\n");
	else
		printf("  -> ERROR!\n");

	enabled = isFontEngineEnabled();
	if (enabled == 1)
		printf("\nFont Engine is enabled.\n");
	else
		if (enabled == 0)
			printf("\nFont Engine is disabled.\n");
		else
			printf("\n!!!ERROR!!! (during isFontEngineEnabled)\n");

	enabled = isHintingEnabled();
	if (enabled == 1)
		printf("\nGlobal hinting is enabled.\n");
	else
		if (enabled == 0)
			printf("\nGlobal hinting is disabled.\n");
		else
			printf("\n!!!ERROR!!! (during isHintingEnabled)\n");

	enabled = isAntiAliasingEnabled();
	if (enabled == 1)
		printf("\nAntiAliasing is enabled.\n");
	else
		if (enabled == 0)
			printf("\nAntiAliasing is disabled.\n");
		else
			printf("\n!!!ERROR!!! (during isAntiAliasingEnabled)\n");

	enabled = isSubPixelEnabled();
	if (enabled == 0)
		printf("\nSubPixel rendering is disabled.\n");
	else
		if (enabled == 1)
			printf("\nSubPixel rendering is enabled in horizontal mode.\n");
		else
			if (enabled == 2)
				printf("\nSubPixel rendering is enabled in vertical mode.\n");
			else
				if (enabled == 3)
					printf("\nSubPixel rendering is enabled in light mode.\n");
				else
					printf("\n!!!ERROR!!! (during isSubPixelEnabled)\n");

	rc1 = getFontEngineApplicationCount();
	if (rc1 != ERROR_INTERNAL_ERROR)
		printf("\nApplications: %d\n", rc1);
	else 
		printf("\n!!!ERROR!!! (during getFontEngineApplicationCount)\n");

	/* take the value from the "getFontEngineApplicationCount()" call and */
	/* loop through these applications, STARTING WITH 0!!! */
	printf("\nApplication names:\n");
	for ( i = 0; i < rc1; i++) {
		name = calloc(255,1);
		rc = getApplicationInformation(i, name, 255, &enabled);
		if (rc == ERROR_INTERNAL_ERROR)
			printf("\n!!!ERROR!!! (during getApplicationInformation)\n");
		else {
			printf("   Name = %s \t\t(Enabled = %d)\n", name, enabled);
		}
		free(name);
	}

	printf("\nAdding application test123.exe \n");
	rc = addApplication("test123.exe");
	if (!rc)
		printf("  -> test123.exe added\n");
	else
		printf("\n!!!ERROR!!! (during addApplication)\n");

	printf("\nDeleting application test123.exe \n");
	rc = deleteApplication("test123.exe");
	if (!rc)
		printf("  -> test123.exe deleted\n");
	else
		printf("\n!!!ERROR!!! (during deleteApplication)\n");

	return 0;
}
