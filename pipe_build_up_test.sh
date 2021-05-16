#!/bin/bash
set -e

readonly MY_DIR="$( cd "$( dirname "${0}" )" && pwd )"

${MY_DIR}/../image_builder/build_test_push_notify.sh "${MY_DIR}"
