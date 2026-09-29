# Problem Statement

## 1. Preamble

This document presents a simulated context in which UK Labs, an English company that has a network
of clinical analysis laboratories, intends to explore and validate an application to manage the clinical
analyses performed in its laboratories. To this end, the organization decided to start the development
of a new software product (prototype) in collaboration with the faculty and students of LETI-ESOFT.

The software product described herein is, on the one hand, designed to promote:

1. The consolidation and acquisition of new competencies related to software development, by
students.
2. The practice and internalization of the recommended working methods and best practices
   commonly adopted in the software industry.

On the other hand, the software product is used to evaluate students throughout the semester, in
alignment with the approved [course syllabus](https://portal.isep.ipp.pt/intranet/education/visualiza_ficha_uc_v10.aspx?cde=85330) (cf. ISEP Portal).

For the project’s development, students must form teams of four elements (exceptionally three) from
the same lab class and communicate their composition to the LETI-ESOFT faculty (cf. formalized
[groups/teams](https://moodle.isep.ipp.pt/pluginfile.php/107231/mod_resource/content/18/LETI-ESOFT26-27-Teams.pdf) on Moodle). Each team will operate as an independent supplier company, competing to
be selected/hired to deliver the intended software product. To achieve this, all teams need to develop
a prototype meeting all (or most) of the specified software requirements and demonstrate that their
development process ensures high product quality, while employing appropriate working methods and
industry best practices.

## 2. Intended Software Product

*UK Labs* is an English company that wants an application to manage the clinical analyses performed in
its network of clinical analysis laboratories. The software application should be conceived having in
mind that it can be further commercialized to other companies besides *UK Labs*.

### 2.1 Business Context

*UK Labs* operates in the English market. It has headquarters in London and a network of clinical analysis
laboratories spread across England, where different types of analysis are performed, as well as
Covid-19 tests. In England, *UK Labs* has exclusivity for Covid-19 testing throughout the territory, which means that no other company can perform this type of testing. However, only a subset of its
laboratories performs Covid-19 tests.

The set of UK Labs clinical analysis laboratories form a network that covers all England, and it is
responsible for collecting samples and interacting with clients. The samples collected by the network
of laboratories are then sent to the chemical laboratory located in the company's headquarters and
the chemical analyses are performed there.

Laboratories are characterized by a code, an address, a phone number, an e-mail address and
opening/closing hour. As the allocation of receptionists and clinical/medical staff to the laboratories
might be complex, by now, the system might assume that receptionists and clinical/medical staff can
work on any laboratory.

Typically, the client arrives at one of the clinical analysis laboratories with a lab order prescribed by a
doctor. Once there, a receptionist asks for the client’s citizen card number and the lab order (which
contains the type of test and the parameters to be measured), and registers in the application the test
to be performed to that client. The date of the prescription as well as the date and the laboratory
where the samples will be collected are also associated with the test. Then, the client should wait until
a medical lab technician calls him/her to collect the samples required to perform the test.

The type of test is characterized by an internal code, an NHS code and a description that identifies the
sample collection method. Each parameter is characterized by a unique code, a name, a description, a
metric (e.g. g/dL, mg/dL, U/l) and reference values (minimum and maximum), if applicable.

Blood tests are frequently characterized by measuring several parameters such as the number of Red
Blood Cells (RBC), White Blood Cells (WBC), Platelets (PLT), among others. Covid tests are characterized
by measuring a single parameter stating whether it is a positive or a negative result. The system should
be developed having in mind the need to easily support other types of tests, regardless of whether
they are based on measuring one or more parameters.

In case of a new client, the receptionist registers him/her in the application. To register a client, the
receptionist needs the client’s name, citizen card number, National Healthcare Service (NHS) number,
date of birth, sex, Tax Identification number (TIF), phone number and e-mail address.

All the tests (e.g. blood, urine, Covid-19) performed by the network of laboratories are registered
locally by the medical lab technicians who collect the samples. The samples are sent daily to the
chemical laboratory where the chemical analyses are performed, and results obtained. When sampling
(e.g. blood or urine sample, swab) the medical lab technician records the samples in the system,
associating them with the client/test, and identifying each sample with a barcode that is automatically
generated using an external API.

At the company's headquarters, the clinical chemistry technologist receives the samples (delivered by
a courier) and performs the chemical analysis, recording the results in the software application. For
each parameter, the clinical chemistry technologist records the value obtained and the date and time
of the chemical analysis.

After completing the chemical analysis, the results are examined by a specialist doctor who makes a
diagnosis and writes a report that will be available to the client. The client only has access to the results
after the report has been prepared by the specialist doctor. To facilitate the access to results, the
application must allow sorting by the client’s TIF or by the client’s name.

Finally, after the specialist doctor has completed the diagnosis, the results of the clinical analyses and
the report become available in the system and the client receives a notification (by SMS and/or e-mail)
alerting that the results are already available in the central application and informing that he/she must
access the application to view those results.

The UK Labs has administrators who are responsible for properly configuring and managing the core
information (e.g. test types, parameters, clinical analysis laboratories, employees) required for the
application to be operated daily by receptionists, clients, medical lab technicians, etc.

## 3. Sprints

As the team should adopt a Software Development Process (SDP) relying on the Iterative and Incremental (I&I) principles,
the project requirements and their priorities are organized in sprints and described by means of User Stories (US).

User stories are used to specify the main goals of each sprint. They are presented from the perspective of system users and their respective roles. In addition, the Project Manager role is used to capture requirements that are not directly associated with any specific system user.

### 3.1 Sprint 1

Requirements:

- As Project Manager, I want the team to setup its own working environment (e.g. repository).
[Priority: High]
- As Project Manager, I want the team to construct a glossary for the current project. [Priority: High]
- As Project Manager, I want the team to investigate the project’s functional and non-functional
requirements and capture them using both a Use Case Diagram and a Supplementary Specification
document. [Priority: High]
- As Project Manager, I want the team to elaborate a domain model that reflects its understanding
of the application domain, including the rationale behind the identification of concepts and
associations. [Priority: High]

### 3.2 Sprint 2

(to be defined)

### 3.3 Sprint 3

(to be defined)

### 3.4 Sprint 4

(to be defined)