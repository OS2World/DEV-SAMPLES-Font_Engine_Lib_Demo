/**************************************************/
/* Font Engine Configuration Library Include File */
/* Autor: Robert Henschel                         */
/* created : 27.12.2005                           */
/* modified: 30.12.2005                           */

#ifndef _feconfigh_
#define _feconfigh_

/*** Constants ***/
#define NO_ERROR                          0
#define ERROR_FONT_ENGINE_NOT_INSTALLED   200
#define ERROR_INTERNAL_ERROR              201

#define FONT_ENGINE_BASE                  "Software\\InnoTek\\InnoTek Font Engine"
#define FONT_ENGINE_HINTING               "Software\\InnoTek\\InnoTek Font Engine\\Hinting"
#define FONT_ENGINE_ANTIALIASING          "Software\\InnoTek\\InnoTek Font Engine\\AntiAliasing"
#define FONT_ENGINE_APPLICATIONS          "Software\\InnoTek\\InnoTek Font Engine\\Applications"


/*** Functions **/

/* detectFontEngine **********************************************************/
/* Parameters: none                                                          */
/* Returns:    0 .. all ok                                                   */
/*             ERROR_FONT_ENGINE_NOT_INSTALLED .. font engine not installed  */
int detectFontEngine(void);

/* isFontEngineEnabled *************************/
/* Parameters: none                            */
/* Returns:    0 .. font engine disabled       */
/*             1 .. font engine enabled        */
/*             else .. error                   */
int isFontEngineEnabled(void);

/* enableFontEngine ***************************/
/* Parameters: none                            */
/* Returns:    0 .. font engine is enabled     */
/*             else .. error                   */
int enableFontEngine(void);

/* disableFontEngine ***************************/
/* Parameters: none                            */
/* Returns:    0 .. font engine is disabled    */
/*             else .. error                   */
int disableFontEngine(void);

/* isHintingEnabled *************************/
/* Parameters: none                            */
/* Returns:    0 .. hinting disabled           */
/*             1 .. hinting enabled            */
/*             else .. error                   */
int isHintingEnabled(void);

/* enableHinting *******************************/
/* Parameters: none                            */
/* Returns:    0 .. hinting is enabled         */
/*             else .. error                   */
int enableHinting(void);

/* disableHinting ******************************/
/* Parameters: none                            */
/* Returns:    0 .. hinting is disabled        */
/*             else .. error                   */
int disableHinting(void);

/* isAntiAliasingEnabled ***********************/
/* Parameters: none                            */
/* Returns:    0 .. AntiAliasing disabled      */
/*             1 .. AntiAliasing enabled       */
/*             else .. error                   */
int isAntiAliasingEnabled(void);

/* enableAntiAliasing **************************/
/* Parameters: none                            */
/* Returns:    0 .. AntiAliasing is enabled    */
/*             else .. error                   */
int enableAntiAliasing(void);

/* disableAntiAliasing ************************/
/* Parameters: none                            */
/* Returns:    0 .. AntiAliasing is disabled   */
/*             else .. error                   */
int disableAntiAliasing(void);

/* isSubPixelEnabled *******************************************/
/* Parameters: none                                            */
/* Returns:    0 .. SubPixel rendering disabled                */
/*             1 .. SubPixel rendering set to horizontal mode  */
/*             2 .. SubPixel rendering set to vertical mode    */
/*             3 .. SubPixel rendering set to light mode       */
/*             else .. error                                   */
int isSubPixelEnabled(void);

/* enableHorizontalSubPixel ***********************************/
/* Parameters: none                                           */
/* Returns:    0 .. Horizontal SubPixel rendering is enabled  */
/*             else .. error                                  */
int enableHorizontalSubPixel(void);

/* enableVerticalSubPixel ***********************************/
/* Parameters: none                                         */
/* Returns:    0 .. Vertical SubPixel rendering is enabled  */
/*             else .. error                                */
int enableVerticalSubPixel(void);

/* enableLightSubPixel ***********************************/
/* Parameters: none                                      */
/* Returns:    0 .. Light SubPixel rendering is enabled  */
/*             else .. error                             */
int enableLightSubPixel(void);

/* disableSubPixel ***********************************/
/* Parameters: none                                  */
/* Returns:    0 .. SubPixel rendering is disabled   */
/*             else .. error                         */
int disableSubPixel(void);


/* getFontEngineApplicationCount **********************/
/* Parameters: none                                   */
/* Returns:    number of applications listed in the   */
/*             font engine registry tree              */
/*             or                                     */
/*             ERROR_INTERNAL_ERROR                   */
/* Note:       This function returns the total count, */
/*             not evaluating whether the application */
/*             is enabled or not!                     */
int getFontEngineApplicationCount(void);

/* getApplicationInformation *************************************/
/* Parameters: long  .. ID (the ID of the application to query)  */
/*             PCHAR .. name (a buffer for the application name) */
/*             long  .. length (the length of the buffer)        */
/*             int * .. enabled (is the application enabled)     */
/* Returns:    0 .. all ok                                       */
/*             ERROR_INTERNAL_ERROR                              */
int getApplicationInformation(long, PCHAR, long, int*);

/* getApplication *********************************************/
/* Parameters: PCHAR .. name (the name of the application)       */
/* Returns:    0 .. application is disabled                      */
/*             1 .. application is enabled                       */
/*             ERROR_INTERNAL_ERROR                              */
int getApplication(PCHAR);

/* enableApplication *********************************************/
/* Parameters: PCHAR .. name (the name of the application)       */
/* Returns:    0 .. all ok, application is enabled               */
/*             ERROR_INTERNAL_ERROR                              */
int enableApplication(PCHAR);

/* disableApplication ********************************************/
/* Parameters: PCHAR .. name (the name of the application)       */
/* Returns:    0 .. all ok, application is disabled              */
/*             ERROR_INTERNAL_ERROR                              */
int disableApplication(PCHAR);

/* addApplication ************************************************/
/* Parameters: PCHAR .. name (the name of the application)       */
/* Returns:    0 .. all ok, application was added and is enabled */
/*             ERROR_INTERNAL_ERROR                              */
int addApplication(PCHAR);

/* deleteApplication *********************************************/
/* Parameters: PCHAR .. name (the name of the application)       */
/* Returns:    0 .. all ok, application deleted                  */
/*             ERROR_INTERNAL_ERROR                              */
int deleteApplication(PCHAR);

#endif
