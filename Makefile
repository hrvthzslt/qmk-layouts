.DEFAULT_GOAL := help

qmk_path := $(HOME)/qmk_firmware
keychron_path := $(HOME)/qmk_firmware_keychron

help:
	@grep -h -E '^[a-zA-Z0-9_-]+:.*?# .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?# "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

install: # Install and setup qmk firmware
	@echo "Installing qmk firmware"
	./scripts/qmk_install

keychron-install: # Install and setup keychron qmk repo
	git clone -b wireless_playground https://github.com/Keychron/qmk_firmware.git $(keychron_path)
	cd $(keychron_path) && git remote add upstream https://github.com/qmk/qmk_firmware.git
	qmk config user.qmk_home=$(keychron_path)
	qmk setup
	qmk config user.qmk_home=$(qmk_path)

setup: # Setup home and userspace
	qmk config user.qmk_home=$(qmk_path)
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

k11-compile: # Compile custom keychron k11 max ansi encoder rgb layout
	qmk config user.qmk_home=$(keychron_path)
	qmk userspace-add -kb keychron/k11_max/ansi_encoder/rgb -km hrvthzslt
	qmk compile -kb keychron/k11_max/ansi_encoder/rgb -km hrvthzslt
	qmk config user.qmk_home=$(qmk_path)
