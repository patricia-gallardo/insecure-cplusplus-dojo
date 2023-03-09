#!/bin/bash -Eeu

readonly MY_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
readonly TMP_DIR="$(mktemp -d /tmp/cyber-dojo-image-builder.XXXXXXX)"
remove_tmp_dir() { rm -rf "${TMP_DIR}" > /dev/null; }
trap remove_tmp_dir INT EXIT

process_cdl_image_src_dir()
{
  local -r name=image_build_test_push_notify.sh
  if [ -x "$(command -v ${name})" ]; then
    >&2 echo "Found executable ${name} on the PATH"
    echo "${name}"
  else
    local -r github=raw.githubusercontent.com
    local -r org=cyber-dojo-tools
    local -r repo=image_builder
    local -r branch=master
    local -r url="https://${github}/${org}/${repo}/${branch}/${name}"
    >&2 echo "Did not find executable ${name} on the PATH"
    >&2 echo "Attempting to curl it from ${url}"
    curl --fail --output "${TMP_DIR}/${name}" --silent "${url}"
    chmod 700 "${TMP_DIR}/${name}"
    echo "${TMP_DIR}/${name}"
  fi
}

"$(process_cdl_image_src_dir)" "${1:-${MY_DIR}}"