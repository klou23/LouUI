/** @mainpage LouUI
 *
 * @section introduction Introduction
 *
 * Welcome to LouUI. This is a library designed to make programming a UI on
 * the VEX brain easier. It can be used in combination with the PROS library.
 * This library is only compatible with C++ development, and not C.
 * <br><br>
 * Creating a UI is very useful because it allows for easy autonomous
 * selection and can make debugging easier.
 *
 * @section installation Installation
 *
 * @subsubsection step1 Step 1: PROS Installation
 *
 * This step can be skipped if you already have PROS installed on your computer.
 * <br><br>
 * This library works with LVGL 5.3.1, which has been ported to VEX V5
 * through the PROS library, so PROS must be installed. The installation
 * guides for PROS on Windows, macOS, and Linux can be found on
 * the PROS website
 * <a href="https://pros.cs.purdue.edu/v5/getting-started/index.html">here</a>.
 *
 * @subsubsection step2 Step 2: Create a New PROS Project
 *
 * This step can be skipped if you already have a PROS project that you want
 * to use LouUI with.
 * <br><br>
 * This library only works with a PROS project. With the PROS CLI installed,
 * a new project can be created by running `pros conduct new-project .`
 * in the directory you want the project to be created in.
 *
 * @subsubsection step3 Step 3: Download the Library
 *
 * The library can be downloaded from the releases tab of the
 * <a href="https://github.com/klou23/LouUI">GitHub repo</a>. Both the zip
 * and the tar.gz work.
 *
 * @subsubsection step4 Step 4: Adding the Library
 *
 * LouUI can then be added to any PROS project by moving the `LouUI` folder
 * from the downloaded zip or tar.gz into the `src` directory of the project.
 *
 * @section usage Usage
 *
 * Once included in the PROS project, LouUI can be used just like any other
 * C++ library.
 *
 * @subsubsection display Display and Screens
 * The basis of LouUI is a tab-like display system that allows for the
 * creation of multiple different UIs (screens) to be created and allows for
 * the currently displayed screen to be changed using a tab system, similar
 * to a web browser. The first step of building a UI with LouUI is to
 * initialize a Display and add any necessary screens to the display. This is
 * further detailed in documentation for the `Display` class.
 *
 * @subsubsection UIobjects UI Objects
 * LouUI has a set of classes that each represent different UI objects that
 * can be displayed on the brain. These objects can be placed on screens, and
 * in some cases, other objects. Where an object is placed is dependent on
 * the constructor. UI objects also contains a variety of properties that can
 * be edited. Different UI objects have different properties that can be
 * edited. The editable properties, along with the methods to edit the
 * properties, can be found in the documentation for each object.
 *
 * @subsubsection variableDec Variable Declarations
 * LouUI variables need to be persistent. This means that they cannot be
 * local variables that are destroyed after a method is exited. Static
 * variables, class member variables, and global variables all work. However,
 * making all LouUI variables global is recommended because it allows the UI
 * to be dynamically changed during runtime. This is generally being done by
 * adding the `extern` keyword before variable declarations.
 *
 * @subsubsection modify Modifying Object Properties
 * Object properties can be modified using the modifier methods. If only one
 * property needs to be modified, the following syntax can be used.
 *
 * @code
 * object->setSize(50, 50);
 * @endcode
 *
 * If multiple object properties need to be set at once, LouUI contains an
 * easy way to do this:
 *
 * @code
 * object = object->setSize(50, 50)
 *                ->setPosition(10, 10)
 *                ->setColor(Color("BLUE"));
 * @endcode
 *
 */