# Problem Statement

## 1. Preamble

This document presents a (simulated) context in which a company intends to explore and validate a new business idea. 
To this end, the company decided to start the development of a new software product (prototype) in collaboration with the faculty and students of LETI-ESOFT.
Thus, the software product described hereinafter is adapted, on the one hand, to promote:

- the consolidation and acquisition of new competencies related to software development;
- the practice and internalization of the recommended working method and presented best practices, which are commonly used in the software industry;

and, on the other hand, to facilitate presenting and lecturing the contents and competencies described in the LETI-ESOFT syllabus throughout the semester.

Therefore, it will be used as a (small) scenario for demonstrations and practical exercises.


## 2. Company Presentation

**Software for Joe, S.A.** (_**S4J**_) [1] is a startup company based in Porto (Portugal) whose mission is to provide IT solutions (applications) focused and oriented to the daily needs of individual people. 

After its last success with an application that allows the management, control, and monitoring of personal expenses, the company decided to expand its product portfolio by developing an application that facilitates the registration, control and monitoring of personal tasks. 

To pursue that goal, as _**S4J**_ does not currently have the free capacity, it decided to subcontract software development services to LETI-ESOFT.

\
[1] A fictional company.


## 3. Intended Software Product

The application to be developed essentially aims to allow the recording of personal tasks, as well as their control and monitoring. 
In this sense, all functionalities described hereinafter are centered and are carried out by the user/person registered to use the application. 
Regarding the user registration method, user data collection (e.g. name and email) and authentication process, it is expected that this will be done through an integration with the  _JoeProfiles_ system already in use in the company.
Unregistered users can only access to generic information as, for instance, a description of the application goals and to the application credits.

At this moment, it is envisaged that users might categorize tasks using a predefined set of categories maintained by the System Administrator. By simplicity, a category just comprehends a unique alphanumeric code and a brief description.

On the other hand, a task is characterized by having a unique reference, a title, an informal description, and another of a more technical nature, and effort estimation as well as the deadline to be accomplished and the category in which it fits in.

It is intended that the application is capable of alerting the user for tasks whose deadline for completion is approaching and/or has already passed.
Hence, the user must be able to record the beginning and end of tasks.

Exploring the collected information, the user must be also able to access a set of reports comprehending statistical data about his/her performance in a given period of time (e.g. week, month). 
As an example, a report might state the number of completed tasks, the amount of time spent on completing such tasks, the average of time spent on each task; while another report might show a comparison between the predicted effort and the effort really spent on each task.

While developing this system, the team must: 

- adopt the best OO software development practices, such as TDD and the application of GRASP and SOLID patterns;
- adopt the English language as the default for development artifacts, including code;
- implement the core software parts (i.e. the domain business and logic) in C++.

At last, _**S4J**_ recommends the team to concentrate efforts on the development of the domain business logic, which should be widely verified/validated by automatic regression tests.
A rudimentary console User Interface (UI) might be developed just for demonstration purposes (e.g. Sprint Review) since,
further on, it is envisaged that the UI will consist of a mobile application which, by now, is out of scope.


## 4. Sprints

As the team should adopt a Software Development Process (SDP) relying on the Iterative and Incremental (I&I) principles,
the project requirements and their priorities are organized in sprints and described by means of User Stories (US).

User stories are used to specify the main goals of each sprint. They are presented from the perspective of system users and their respective roles. In addition, the Project Manager role is used to capture requirements that are not directly associated with any specific system user.

### 4.1 Sprint 1

Requirements:

- As Project Manager, I want the team to construct a glossary for the current project.
- As Project Manager, I want the team to investigate the project's functional and non-functional requirements and capture them using both a Use Case Diagram and a Supplementary Specification document.
- As Project Manager, I want the team to elaborate a domain model that reflects its understanding of the application domain, including the rationale behind the identification of concepts and associations.

### 4.2 Sprint 2

User stories:

- **US01 -** As System Administrator, I want to create a new category.
  - AC01-1: The category code cannot be empty or have less than five characters.
  - AC01-2: The category description cannot be empty.
- **US02 -** As System Administrator, I want to see a list of all existing categories.
- **US03 -** As System Administrator, I want to update the description of an existing category.
- **US04 -** As System Administrator, I want to delete an existing category.
- **US05 -** As Person, I want to define a new task that I have to complete.
  - AC05-1: The task reference, title, and category are mandatory. The remaining data is optional.

### 4.3 Sprint 3

(to be defined)

### 4.4 Sprint 4

(to be defined)