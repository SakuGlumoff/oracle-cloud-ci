# Oracle Cloud CI

A continuous integration environment set up in [Oracle Cloud][].
[![Build Status](http://132.145.232.104:8080/job/oracle-cloud-ci/job/master/badge/icon)](http://132.145.232.104:8080/job/oracle-cloud-ci/job/master/)

## About

This repository is an example and a personal exercise to use the
[Oracle Cloud Free][] to create a continuous environment wherein
a source code from a repository is compiled, built, tested and then released.

## Process
1. A commit is made to the master branch
2. An automated pipeline is triggered in [Jenkins][]
3. The unit tests are run
   1. The source code is built in unit test configuration
   2. The unit tests are run on a virtual machine
   3. The results of the unit tests are passed back to the pipeline in json format
   4. The json file is parsed and the results shown in Jenkins
4. The integration tests are run
   1. The source code is built in integration test configuration
   2. The integration tests are run on a virtual machine
   3. The results of the integration tests are passed back to the pipeline in json format
   4. The json file is parsed and the results shown in Jenkins
5. The device code is created
   1. The source code is built in release configuration
   2. The built binary is passed back to the pipeline
   3. The binary is archived in Jenkins
6. The pipeline success is reported back to GitHub

## Product in the environment

### Device

The device used in this project is an [STM32 Nucleo F446RE][] development board.

### Program

The program running on a device is made simple for the purpose of this project.   
* The main loop in the unit test configuration runs unit tests
* The main loop in the integration test configuration runs integration tests
* The main loop in the release configuration turns leds on and off

---
Saku Rautio, 2019

[Oracle Cloud]: https://www.oracle.com/cloud/
[Oracle Cloud Free]: https://www.oracle.com/cloud/free/
[Jenkins]: https://jenkins.io/
[STM32 Nucleo F446RE]: https://www.st.com/en/evaluation-tools/nucleo-f446re.html
