# SPP app

## Overview
The SPP application uses the SPP profile library to establish, terminate, send, and receive SPP data over BR/EDR. This sample supports a single SPP connection.

## Features demonstrated
- Use of Bluetooth SPP library

## Instructions
To demonstrate the app, work through the following steps:

1. Build and download the application to the WICED board.
2. Open the BT/BLE Profile Client Control application and open the port for WICED HCI for the device. Default baud rate configured in the application is defined by the BSP HCI\_UART\_DEAULT\_BAUD #define, usually either 3M or 115200 depending on board UART capabilities.
3. Run the BTSpy program to view protocol and application traces.
4. On Windows 10 PCs, right click on the Bluetooth icon in the system tray and select 'Add a Bluetooth Device'. Find and pair with the spp app. That will create an incoming and an outgoing COM port on your computer. Right click on the Bluetooth icon in the system tray and select 'Open Settings', scroll down and select "More Bluetooth options" and then select the 'COM Ports' tab.
5. Use application such as Term Term to open the outgoing COM port. Opening the port will create the SPP connection.
6. Type any key on the terminal of the outgoing COM port, the spp application will receive the key.
7. For 20721B2 based WICED kits, use the Custom button on audio shield board as application button rather than the button on the base board.

## Notes
See the spp.c file for compile flag options for different modes of testing. CYW9M2BASE-43012BT does not support SEND\_DATA ON INTERRUPT because the platform does not have button connected to BT board.

To test SEND\_DATA ON INTERRUPT with CYW943012BTEVK-01, the audio shield board should be removed. To make use of the USER button a jumper wire should be installed to connect P00 from A2 (J2 pin 3) to RSVD_1_USER_BTN (J12 pin 1).

## Application Settings
- SEND\_DATA
    - This command line option enables sends data to peer side. Use parameter INTERRUPT or TIMEOUT.
    - If INTERRUPT is used then the application sends 1 MB data to the peer application on every App button press on the WICED board. This is default.
    - It TIMEOUT is used then the application sends 4 bytes every second while session is up.

- LOOPBACK\_DATA
    -  If LOOPBACK_DATA=1, the app sends back received data.
## Common application settings

Application settings below are common for all BTSDK applications and can be configured via the makefile of the application or passed in via the command line.

**BT\_DEVICE\_ADDRESS**
> Set the BDA (Bluetooth Device Address) for your device. The address is 6 bytes, for example, 20819A10FFEE. By default, the SDK will set a BDA for your device by combining the 7 hex digit device ID with the last 5 hex digits of the host PC MAC address.

**UART**
> Set to the UART port you want to use to download the application. For example 'COM6' on Windows or '/dev/ttyWICED\_HCI\_UART0' on Linux or '/dev/tty.usbserial-000154' on macOS. By default, the SDK will auto-detect the port.

**ENABLE_DEBUG**
> For HW debugging, configure ENABLE\_DEBUG=1. See the document [WICED-Hardware-Debugging](https://github.com/cypresssemiconductorco/btsdk-docs/blob/master/docs/BT-SDK/WICED-Hardware-Debugging.pdf) for more information. This setting configures GPIO for SWD.<br>
>
   - CYW920819EVB-02/CYW920820EVB-02: SWD signals are shared with D4 and D5, see SW9 in schematics.
   - CYBT-213043-MESH/CYBT-213043-EVAL/CYBT-243053-EVAL/CYBT-253059-EVAL/CYBT-253059-EVAL: SWD signals are routed to P12=SWDCK and P13=SWDIO. Use expansion connectors to connect VDD, GND, SWDCK, and SWDIO to your SWD Debugger probe.
   - CYBT-223058-EVAL/CYBT-243053-EVAL/CYW920835M2EVB-01: SWD signals are routed to P02=SWDCK and P03=SWDIO. Use expansion connectors to connect VDD, GND, SWDCK, and SWDIO to your SWD Debugger probe.
   - CYBT-263065-EVAL/CYBT-273063-EVAL: SWD signals are routed to P02=SWDCK and P04=SWDIO. Use expansion connectors to connect VDD, GND, SWDCK, and SWDIO to your SWD Debugger probe.
   - CYBT-343026-EVAL/CYBT-353027-EVAL: SWD signals are routed to P11=SWDCK and P15=SWDIO. Use expansion connectors to connect VDD, GND, SWDCK, and SWDIO to your SWD Debugger probe.
   - CYBT-343052-EVAL: SWD signals are routed to P02=SWDCK and P03=SWDIO. Use expansion connectors to connect VDD, GND, SWDCK, and SWDIO to your SWD Debugger probe.
   - CYBT-413055-EVAL/CYBT-413061-EVAL: SWD signals are routed to P16=SWDCK and P17=SWDIO. Use expansion connectors to connect VDD, GND, SWDCK, and SWDIO to your SWD Debugger probe.
   - CYW989820EVB-01: SWDCK (P02) is routed to the J13 DEBUG connector, but not SWDIO. Add a wire from J10 pin 3 (PUART CTS) to J13 pin 2 to connect GPIO P10 to SWDIO.
   - CYW920719B2Q40EVB-01: PUART RX/TX signals are shared with SWDCK and SWDIO. Remove RX and TX jumpers on J10 when using SWD. PUART and SWD cannot be used simultaneously on this board unless these pins are changed from the default configuration.
   - CYW920721B2EVK-02: SWD signals are shared with D4 and D5, see SW9 in schematics.
   - CYW920721M2EVK-02: The default setup uses P03 for SWDIO and P05 for SWDCK. Check the position of SW15 if using JLink with the DEBUG connector.
   - CYW920706WCDEVAL: SWD debugging requires fly-wire connections. The default setup P15 (J22 pin 3 or J24 pin 1) for SWDIO and P11 (J23 pin 5
    or J22 pin 4) for SWDCK.
   - CYW920735Q60EVB-01: SWD hardware debugging supported. The default setup uses the J13 debug header, P3 (J13 pin 2) for SWDIO and P2 (J13 pin 4) for SWDCK.  They can be optionally routed to D4 and D4 on the Arduino header J4, see SW9 in schematics.
   - SWD hardware debugging is not supported on the following:
   >- CYW920721M2EVK-01
   >- CYW920835REF-RCU-01
   >- CYW920819REF-KB-01
   >- CYW9M2BASE-43012BT
   >- CYW943012BTEVK-01
   >- CYBT-423054-EVAL
   >- CYBT-423060-EVAL
   >- CYBT-483056-EVAL
   >- CYBT-483062-EVAL

## Building code examples

**Using the ModusToolbox IDE**

1. Install ModusToolbox 2.2 (or higher).
2. In the ModusToolbox IDE, click the **New Application** link in the Quick Panel (or, use **File > New > ModusToolbox IDE Application**).
3. Pick your board for BTSDK under AIROC Bluetooth BSPs.
4. Select the application in the IDE.
5. In the Quick Panel, select **Build** to build the application.
6. To program the board (download the application), select **Program** in the Launches section of the Quick Panel.


**Using command line**

1. Install ModusToolbox 2.2 (or higher).
2. On Windows, use Cygwin from \ModusToolbox\tools_2.x\modus-shell\Cygwin.bat to build apps.
3. Use the tool 'project-creator-cli' under \ModusToolbox\tools_2.x\project-creator\ to create your application.<br/>
   > project-creator-cli --board-id (BSP) --app-id (appid) -d (dir) <br/>
   See 'project-creator-cli --help' for useful options to list all available BSPs, and all available apps per BSP.<br/>
   For example:<br/>
   > project-creator-cli --app-id mtb-example-btsdk-empty --board-id CYW920706WCDEVAL -d .<br/>
4. To build the app call make build. For example:<br/>
   > cd mtb-examples-btsdk-empty<br/>
   > make build<br/>
5. To program (download to) the board, call:<br/>
   > make qprogram<br/>
6. To build and program (download to) the board, call:<br/>
   > make program<br/><br>
   Note: make program = make build + make qprogram

## Downloading an application to a board

If you have issues downloading to the board, follow the steps below:

- Press and hold the 'Recover' button on the board.
- Press and hold the 'Reset' button on the board.
- Release the 'Reset' button.
- After one second, release the 'Recover' button.

Note: this is only applicable to boards that download application images to FLASH storage. Boards that only support RAM download (DIRECT_LOAD) such as CYW9M2BASE-43012BT can be power cycled to boot from ROM.

## Over The Air (OTA) Firmware Upgrade
Applications that support OTA upgrade can be updated via the peer OTA app in:<br>
>\<Workspace Dir>\mtb\_shared\wiced\_btsdk\tools\btsdk-peer-apps-ota<br>

See the readme.txt file located in the above folder for instructions.<br>
To generate the OTA image for the app, configure OTA\_FW\_UPGRADE=1 in the app
makefile, or append OTA\_FW\_UPGRADE=1 to a build command line, for example:
> make PLATFORM=CYW955572BTEVK-01 OTA\_FW\_UPGRADE=1 build<br>

This will the generate \<app>.bin file in the 'build' folder.

## SDK software features

- Dual-mode Bluetooth stack included in the ROM (BR/EDR and LE)
- Bluetooth stack and profile level APIs for embedded Bluetooth application development
- WICED HCI protocol to simplify host/MCU application development
- APIs and drivers to access on-board peripherals
- Bluetooth protocols include GAP, GATT, SMP, RFCOMM, SDP, AVDT/AVCT, LE Mesh
- LE and BR/EDR profile APIs, libraries, and sample apps
- Support for Over-The-Air (OTA) upgrade
- Device Configurator for creating custom pin mapping
- Bluetooth Configurator for creating LE GATT Database
- Peer apps based on Android, iOS, Windows, etc. for testing and reference
- Utilities for protocol tracing, manufacturing testing, etc.
- Documentation for APIs, datasheets, profiles, and features
- BR/EDR profiles: A2DP, AVRCP, HFP, HSP, HID, SPP, MAP, PBAP, OPP
- LE profiles: Mesh profiles, HOGP, ANP, BAP, HRP, FMP, IAS, ESP, LE COC
- Apple support: Apple Media Service (AMS), Apple Notification Center Service (ANCS), iBeacon, Homekit, iAP2
- Google support: Google Fast Pair Service (GFPS), Eddystone
- Amazon support: Alexa Mobile Accessories (AMA)

Note: this is a list of all features and profiles supported in BTSDK, but some AIROC devices may only support a subset of this list.

## List of boards available for use with BTSDK

- [CYW20819A1 chip](https://github.com/cypresssemiconductorco/20819A1)
    - [CYW920819EVB-02](https://github.com/cypresssemiconductorco/TARGET_CYW920819EVB-02), [CYBT-213043-MESH](https://github.com/cypresssemiconductorco/TARGET_CYBT-213043-MESH), [CYBT-213043-EVAL](https://github.com/cypresssemiconductorco/TARGET_CYBT-213043-EVAL), [CYW920819REF-KB-01](https://github.com/cypresssemiconductorco/TARGET_CYW920819REF-KB-01), [CYBT-223058-EVAL](https://github.com/cypresssemiconductorco/TARGET_CYBT-223058-EVAL), [CYBT-263065-EVAL](https://github.com/cypresssemiconductorco/TARGET_CYBT-263065-EVAL), [CYBT-273063-EVAL](https://github.com/cypresssemiconductorco/TARGET_CYBT-273063-EVAL)
- [CYW20820A1 chip](https://github.com/cypresssemiconductorco/20820A1)
    - [CYW920820EVB-02](https://github.com/cypresssemiconductorco/TARGET_CYW920820EVB-02), [CYW989820EVB-01](https://github.com/cypresssemiconductorco/TARGET_CYW989820EVB-01), [CYBT-243053-EVAL](https://github.com/cypresssemiconductorco/TARGET_CYBT-243053-EVAL), [CYBT-253059-EVAL](https://github.com/cypresssemiconductorco/TARGET_CYBT-253059-EVAL)
- [CYW20721B2 chip](https://github.com/cypresssemiconductorco/20721B2)
    - [CYW920721B2EVK-02](https://github.com/cypresssemiconductorco/TARGET_CYW920721B2EVK-02), [CYW920721M2EVK-01](https://github.com/cypresssemiconductorco/TARGET_CYW920721M2EVK-01), [CYW920721M2EVK-02](https://github.com/cypresssemiconductorco/TARGET_CYW920721M2EVK-02), [CYBT-423060-EVAL](https://github.com/cypresssemiconductorco/TARGET_CYBT-423060-EVAL), [CYBT-483062-EVAL](https://github.com/cypresssemiconductorco/TARGET_CYBT-483062-EVAL), [CYBT-413061-EVAL](https://github.com/cypresssemiconductorco/TARGET_CYBT-413061-EVAL)
- [CYW20719B2 chip](https://github.com/cypresssemiconductorco/20719B2)
    - [CYW920719B2Q40EVB-01](https://github.com/cypresssemiconductorco/TARGET_CYW920719B2Q40EVB-01), [CYBT-423054-EVAL](https://github.com/cypresssemiconductorco/TARGET_CYBT-423054-EVAL), [CYBT-413055-EVAL](https://github.com/cypresssemiconductorco/TARGET_CYBT-413055-EVAL), [CYBT-483056-EVAL](https://github.com/cypresssemiconductorco/TARGET_CYBT-483056-EVAL)
- [CYW20706A2 chip](https://github.com/cypresssemiconductorco/20706A2)
    - [CYW920706WCDEVAL](https://github.com/cypresssemiconductorco/TARGET_CYW920706WCDEVAL), [CYBT-353027-EVAL](https://github.com/cypresssemiconductorco/TARGET_CYBT-353027-EVAL), [CYBT-343026-EVAL](https://github.com/cypresssemiconductorco/TARGET_CYBT-343026-EVAL)
- [CYW20735B1 chip](https://github.com/cypresssemiconductorco/20735B1)
    - [CYW920735Q60EVB-01](https://github.com/cypresssemiconductorco/TARGET_CYW920735Q60EVB-01), [CYBT-343052-EVAL](https://github.com/cypresssemiconductorco/TARGET_CYBT-343052-EVAL)
- [CYW20835B1 chip](https://github.com/cypresssemiconductorco/20835B1)
    - [CYW920835REF-RCU-01](https://github.com/cypresssemiconductorco/TARGET_CYW920835REF-RCU-01), [CYW920835M2EVB-01](https://github.com/cypresssemiconductorco/TARGET_CYW920835M2EVB-01)
- [CYW43012C0 chip](https://github.com/cypresssemiconductorco/43012C0)
    - [CYW9M2BASE-43012BT](https://github.com/cypresssemiconductorco/TARGET_CYW9M2BASE-43012BT), [CYW943012BTEVK-01](https://github.com/cypresssemiconductorco/TARGET_CYW943012BTEVK-01)


## Folder structure

All BTSDK code examples need the 'mtb\_shared\wiced\_btsdk' folder to build and test the apps. 'wiced\_btsdk' includes the 'dev-kit' and 'tools' folders. The contents of the 'wiced\_btsdk' folder will be automatically populated incrementally as needed by the application being used.

**dev-kit**

This folder contains the files that are needed to build the embedded Bluetooth apps.

* baselib: Files for chips supported by BTSDK. For example CYW20819, CYW20719, CYW20706, etc.

* bsp: Files for BSPs (platforms) supported by BTSDK. For example CYW920819EVB-02, CYW920721B2EVK-02, CYW920706WCDEVAL etc.

* btsdk-include: Common header files needed by all apps and libraries.

* btsdk-tools: Build tools needed by BTSDK.

* libraries: Profile libraries used by BTSDK apps such as audio, LE, HID, etc.

**tools**

This folder contains tools and utilities need to test the embedded Bluetooth apps.

* btsdk-host-apps-bt-ble: Host apps (Client Control) for LE and BR/EDR embedded apps, demonstrates the use of WICED HCI protocol to control embedded apps.

* btsdk-host-peer-apps-mesh: Host apps (Client Control) and Peer apps for embedded Mesh apps, demonstrates the use of WICED HCI protocol to control embedded apps, and configuration and provisioning from peer devices.

* btsdk-peer-apps-ble: Peer apps for embedded LE apps.

* btsdk-peer-apps-ota: Peer apps for embedded apps that support Over The Air Firmware Upgrade.

* btsdk-utils: Utilities used in BTSDK such as BTSpy, wmbt, and ecdsa256.

See README.md in the sub-folders for more information.

## Software Tools
The following tool applications are installed on your computer either with ModusToolbox, or by creating an application in the workspace that can use the tool.

**BT Spy:**<br>
>   BTSpy is a trace viewer utility that can be used with WICED BT platforms to
    view protocol and application trace messages from the embedded device. The
    utility is located in the folder below. For more information, see readme.txt in the same folder.<br>
    This utility can be run directly from the filesystem, or it can be run from
    the Tools section of the ModusToolbox IDE QuickPanel, or by right-clicking
    a project in the IDE Project Explorer pane and selecting the ModusToolbox
    context menu.<br>
    It is supported on Windows, Linux and macOS.<br>
    Location:  \<Workspace Dir>\wiced_btsdk\tools\btsdk-utils\BTSpy

**BT/LE Profile Client Control:**<br>
>   This application emulates host MCU applications for LE and BR/EDR profiles.
    It demonstrates WICED BT APIs. The application communicates with embedded
    apps over the WICED HCI interface. The application is located in the folder
    below. For more information, see readme.txt in the same folder.<br>
    This utility can be run directly from the filesystem, or it can be run from
    the Tools section of the ModusToolbox IDE QuickPanel, or by right-clicking
    a project in the IDE Project Explorer pane and selecting the ModusToolbox
    context menu.<br>
    It is supported on Windows, Linux, and macOS.<br>
    Location:  \<Workspace Dir>\wiced\_btsdk\tools\btsdk-host-apps-bt-ble\client_control

**LE Mesh Client Control:**<br>
>   Similar to the above app, this application emulates host MCU applications
    for LE Mesh models. It can configure and provision mesh devices and create
    mesh networks. The application is located in the folder below. For more
    information, see readme.txt in the same folder.<br>
    This utility can be run directly from the filesystem, or it can be run from
    the Tools section of the ModusToolbox IDE QuickPanel (if a mesh-capable
    project is selected in the IDE Project Explorer pane), or by right-clicking
    a mesh-capable project in the IDE Project Explorer pane and selecting the
    ModusToolbox context menu.<br>
    The full version is provided for Windows (VS\_ClientControl) supporting all
    Mesh models.<br>
    A limited version supporting only the Lighting model (QT\_ClientControl) is
    provided for Windows, Linux, and macOS.<br>
    Location:  \<Workspace Dir>\wiced_btsdk\tools\btsdk-host-peer-apps-mesh\host

**Peer apps:**<br>
>   Applications that run on Windows, iOS or Android and act as peer BT apps to
    demonstrate specific profiles or features, communicating with embedded apps
    over the air.<br>
    LE apps location:  \<Workspace Dir>\wiced\_btsdk\tools\btsdk-peer-apps-ble<br>
    LE Mesh apps location:  \<Workspace Dir>\wiced\_btsdk\tools\btsdk-host-peer-apps-mesh\peer<br>
    OTA apps location:  \<Workspace Dir>\wiced\_btsdk\tools\btsdk-peer-apps-ota

**Device Configurator:**<br>
>   Use this GUI tool to create source code for a custom pin mapping for your device. Run this tool
    from the Tools section of the ModusToolbox IDE QuickPanel, or by
    right-clicking a project in the IDE Project Explorer pane and selecting the
    ModusToolbox context menu.<br>
    It is supported on Windows, Linux and macOS.<br>
    Note: The pin mapping is based on wiced\_platform.h for your board.<br>
    Location:  \<Install Dir>\tools_2.x\device-configurator

**Bluetooth Configurator:**<br>
>   Use this GUI tool to create and configure the LE GATT Database and the BR/EDR SDP Database, generated as source code for your
    application.<br>
    Run this tool from the Tools section of the ModusToolbox IDE QuickPanel, or
    by right-clicking a project in the IDE Project Explorer pane and selecting
    the ModusToolbox context menu.<br>
    It is supported on Windows, Linux and macOS.<br>
    Location:  \<Install Dir>\tools_2.x\bt-configurator

## Tracing
To view application traces, there are 2 methods available. Note that the
application needs to configure the tracing options.<br>

1. WICED Peripheral UART - Open this port on your computer using a serial port
utility such as Tera Term or PuTTY (usually using 115200 baud rate for non-Mesh apps, and 921600 for Mesh apps).<br>
2. WICED HCI UART - Open this port on your computer using the Client Control
application mentioned above (usually using 3M baud rate). Then run the BT Spy
utility mentioned above.

## Using BSPs (platforms)

BTSDK BSPs are located in the \mtb\_shared\wiced\_btsdk\dev-kit\bsp\ folder by default.

#### a. Selecting an alternative BSP

The application makefile has a default BSP. See "TARGET". The makefile also has a list of other BSPs supported by the application. See "SUPPORTED_TARGETS". To select an alternative BSP, use Library Manager from the Quick Panel to deselect the current BSP and select an alternate BSP. Then right-click the newly selected BSP and choose 'Set Active'.  This will automatically update TARGET in the application makefile.

#### b. Custom BSP

**Complete BSP**

To create and use a complete custom BSP that you want to use in applications, perform the following steps:

1. Select an existing BSP created through ModusToolbox Project Creator that you wish to use as a template.
2. Make a copy in the same folder and rename it. For example mtb\_shared\wiced\_btsdk\dev-kit\bsp\TARGET\_mybsp.<br/>
   **Note:** This can be done in the system File Explorer and then refresh the workspace in ModusToolbox to see the new project.  Delete the .git sub-folder from the newly copied folder before refreshing in Eclipse.
   If done in the IDE, an error dialog may appear complaining about items in the .git folder being out of sync.  This can be resolved by deleting the .git sub-folder in the newly copied folder.

3. In the new mtb\_shared\wiced\_btsdk\dev-kit\bsp\TARGET\_mybsp\<branch>\ folder, rename the existing/original (BSP).mk file to mybsp.mk.
4. In the application makefile, set TARGET=mybsp and add it to SUPPORTED\_TARGETS.
5. In the application libs folder, edit the mtb.mk file and replace all instances of the template BSP name string with 'mybsp'.
6. Update design.modus for your custom BSP if needed using the **Device Configurator** link under **Configurators** in the Quick Panel.
7. Update the application makefile as needed for other custom BSP specific attributes and build the application.

**Custom Pin Configuration Only - Multiple Apps**

To create a custom pin configuration to be used by multiple applications using an existing BSP that supports Device Configurator, perform the following steps:

1. Create a folder COMPONENT\_(CUSTOM)\_design\_modus in the existing BSP folder. For example mtb\_shared\wiced\_btsdk\dev-kit\bsp\TARGET\_CYW920819EVB-02\<branch>\COMPONENT\_my\_design\_modus
2. Copy the file design.modus from the reference BSP COMPONENT\_bsp\_design\_modus folder under mtb\_shared\wiced\_btsdk\dev-kit\bsp\ and place the file in the newly created COMPONENT\_(CUSTOM)\_design\_modus folder.
3. In the application makefile, add the following two lines<br/>
   DISABLE\_COMPONENTS+=bsp\_design\_modus<br/>
   COMPONENTS+=(CUSTOM)\_design\_modus<br/>
   (for example COMPONENTS+=my\_design\_modus)
4. Update design.modus for your custom pin configuration if needed using the **Device Configurator** link under **Configurators** in the Quick Panel.
5. Building of the application will generate pin configuration source code under a GeneratedSource folder in the new COMPONENT\_(CUSTOM)\_design\_modus folder.

**Custom Pin Configuration Only - Per App**

To create a custom configuration to be used by a single application from an existing BSP that supports Device Configurator, perform the following steps:

1. Create a folder COMPONENT\_(BSP)\_design\_modus in your application. For example COMPONENT\_CYW920721B2EVK-02\_design\_modus
2. Copy the file design.modus from the reference BSP under mtb\_shared\wiced\_btsdk\dev-kit\bsp\ and place the file in this folder.
3. In the application makefile, add the following two lines<br/>
   DISABLE\_COMPONENTS+=bsp\_design\_modus<br/>
   COMPONENTS+=(BSP)\_design\_modus<br/>
   (for example COMPONENTS+=CYW920721B2EVK-02\_design\_modus)
4. Update design.modus for your custom pin configuration if needed using the **Device Configurator** link under **Configurators** in the Quick Panel.
5. Building of the application will generate pin configuration source code under the GeneratedSource folder in your application.


## Using libraries

The libraries needed by the app can be found in in the mtb\_shared\wiced\_btsdk\dev-kit\libraries folder. To add an additional library to your application, launch the Library Manager from the Quick Panel to add a library. Then update the makefile variable "COMPONENTS" of your application to include the library. For example:<br/>
   COMPONENTS += fw\_upgrade\_lib


## Documentation

BTSDK API documentation is available [online](https://cypresssemiconductorco.github.io/btsdk-docs/BT-SDK/index.html)

Note: For offline viewing, git clone the [documentation repo](https://github.com/cypresssemiconductorco/btsdk-docs)

BTSDK Technical Brief and Release Notes are available [online](https://community.cypress.com/community/software-forums/modustoolbox-bt-sdk)
