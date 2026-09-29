# README #

This repository includes didactic artifacts aimed to support and demonstrate some principles, concepts, approaches, methods and practices lectured in the Software Engineering (ESOFT) course unit of the [Degree in Telecommunications and Informatics Engineering (LETI)](https://www.isep.ipp.pt/Course/Course/473) at the [School of Engineering – Polytechnic of Porto (ISEP)](https://www.isep.ipp.pt).


### What is this repository for? ###

This repository is intended to serve as an **entry point** for students beginning their studies in ESOFT.

To that end, it includes a (very) small demo project illustrating the development of an information system. Specifically, it contains:

- The initial Problem Statement
- Requirements Engineering Artifacts
    - Glossary
    - Use Case Diagram
    - Supplementary Specification (based on FURPS+)
    - User Stories (US)
- OO Analysis
    - Domain Model
- Design Artifacts (organized per US)
    - Sequence Diagram (SD)
    - Class Diagram (CD)
- Automatic Regression Tests
    - Unit Tests
    - Integration Tests
- Code/Implementation (in C++) for some functionalities (User Stories)

**Students are required to follow the organizational structure of this project/repository when preparing their ESOFT assessment project.**

Finally, it is important to note that throughout the semester, these artifacts and code will naturally evolve to reflect the software engineering competencies acquired over time.


### How do I get set up? ###

- Download/Clone the repository
- Open the project using [CLion](https://www.jetbrains.com/clion/)
- The main project (DemoTasks) and its subprojects (TasksCore, TasksCoreTests, and TasksConsoleApp) are loaded and ready for compilation and execution
    - **DemoTasks** acts as an umbrella for the other subprojects — running it triggers the compilation of all dependencies;
    - **TasksCore** is a _library_ containing the domain entities and business logic;
    - **TasksCoreTests** includes a set of regression tests targeting the TasksCore classes;
    - **TasksConsoleApp** is a console-based executable that provides a basic User Interface (UI), allowing users to interact with core application functionalities.
- All projects are configured/compiled using [CMake](https://cmake.org) files
    - A quick CMake tutorial is available [here](https://www.jetbrains.com/help/clion/quick-cmake-tutorial.html)
- To conveniently read and edit UML artifacts, it is required to install the [PlantUML plugin](https://plugins.jetbrains.com/plugin/7017-plantuml-integration)


### Where do I start? ###

- Read the initial [Problem Statement](docs/ProblemStatement.md).
- Explore the artifacts available in the [system documentation](docs/system-documentation) folder. It is recommended to begin with the Requirements Engineering artifacts, followed by the Analysis artifacts. 
- Next review how user functionalities are addressed/fulfilled in the Design artifacts.
- Finally, examine the code to assess how effectively the proposed design has been implemented.


### Who do I talk to? ###

For any questions about this repository you should talk to Alexandre Gouveia ([aas@isep.ipp.pt](mailto:aas@isep.ipp.pt)).