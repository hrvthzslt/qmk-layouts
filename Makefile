.DEFAULT_GOAL := help

help:
	@grep -h -E '^[a-zA-Z0-9_-]+:.*?# .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?# "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

install: # Install and setup qmk firmware
	@echo "Installing qmk firmware"
	./scripts/qmk_install

setup: # Symlink userspace files
	qmk config user.qmk_home=$(HOME)/qmk_firmware/
	qmk config user.overlay_dir=$(pwd)
	qmk userspace-add -kb keychron/q8/iso_encoder -km hrvthzslt
	qmk userspace-add -kb keychron/q11/iso_encoder -km hrvthzslt

q8-compile: setup # Compile custom keychron q8 iso encoder layout
	qmk compile -kb keychron/q8/iso_encoder -km hrvthzslt

q8-flash: setup # Flash custom keychron q8 iso encoder layout
	qmk flash -kb keychron/q8/iso_encoder -km hrvthzslt

q11-compile: setup # Compile custom keychron q11 iso encoder layout
	qmk compile -kb keychron/q11/iso_encoder -km hrvthzslt

q11-flash: setup # Flash custom keychron q11 iso encoder layout
	qmk flash -kb keychron/q11/iso_encoder -km hrvthzslt
