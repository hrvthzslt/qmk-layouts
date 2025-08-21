.DEFAULT_GOAL := help

qmk_path := $(HOME)/qmk_firmware
venv_path := $(qmk_path)/venv
venv_activate := . $(venv_path)/bin/activate

help:
	@grep -h -E '^[a-zA-Z0-9_-]+:.*?# .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?# "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

install: # Install and setup qmk firmware
	@echo "Installing qmk firmware"
	./scripts/qmk_install
	-cd $(qmk_path)
	/usr/bin/python3 -m venv $(venv_path)
	$(venv_activate) && pip install -r $(qmk_path)/requirements.txt

setup: # Symlink userspace files
	$(venv_activate) && qmk config user.qmk_home=$(qmk_path)
	$(venv_activate) && qmk config user.overlay_dir=$(pwd)
	$(venv_activate) && qmk userspace-add -kb keychron/q8/iso_encoder -km hrvthzslt
	$(venv_activate) && qmk userspace-add -kb keychron/q11/iso_encoder -km hrvthzslt

q8-compile: setup # Compile custom keychron q8 iso encoder layout
	$(venv_activate) && qmk compile -kb keychron/q8/iso_encoder -km hrvthzslt

q8-flash: setup # Flash custom keychron q8 iso encoder layout
	$(venv_activate) && qmk flash -kb keychron/q8/iso_encoder -km hrvthzslt

q11-compile: setup # Compile custom keychron q11 iso encoder layout
	$(venv_activate) && qmk compile -kb keychron/q11/iso_encoder -km hrvthzslt

q11-flash: setup # Flash custom keychron q11 iso encoder layout
	$(venv_activate) && qmk flash -kb keychron/q11/iso_encoder -km hrvthzslt
