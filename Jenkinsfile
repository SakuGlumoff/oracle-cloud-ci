pipeline {
  agent {
    node {
      label 'master'
    }

  }
  stages {
    stage('Unit test') {
      agent {
        node {
          label 'master'
        }

      }
      steps {
        dir(path: './device') {
          sh 'git submodule sync --recursive'
          sh 'git submodule update --init --remote --recursive'
          sh 'git submodule update'
          sh 'make clean'
          echo 'Building with config UNIT_TEST'
          sh 'make config=UNIT_TEST'
          fileExists './build/device.exe'
          sh 'chmod +x ./build/device.exe'
          echo 'Running unit tests'
          sh './build/device.exe'
        }

      }
    }
    stage('Build integration tests') {
      agent {
        node {
          label 'arm'
        }

      }
      steps {
        dir(path: './device') {
          sh 'git submodule sync --recursive'
          sh 'git submodule update --init --remote --recursive'
          sh 'git submodule update'
          sh 'make clean'
          echo 'Building with config INTEGRATION_TEST'
          sh 'make config=INTEGRATION_TEST'
          fileExists './build/device.bin'
          echo 'Archiving built binary'
          archiveArtifacts(artifacts: './build/device.bin', onlyIfSuccessful: true)
        }

      }
    }
    stage('Run integration tests') {
      agent {
        node {
          label 'master'
        }

      }
      steps {
        echo 'TODO: Run integration tests'
      }
    }
    stage('Build release') {
      agent {
        node {
          label 'arm'
        }

      }
      steps {
        dir(path: './device') {
          sh 'git submodule sync --recursive'
          sh 'git submodule update --init --remote --recursive'
          sh 'git submdoule update'
          sh 'make clean'
          echo 'Building with config RELEASE'
          sh 'make config=RELEASE'
          fileExists './build/device.bin'
          archiveArtifacts(artifacts: './build/device.bin', onlyIfSuccessful: true)
        }

      }
    }
  }
}