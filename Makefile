.PHONY: help
.DEFAULT_GOAL := help

help:
	@grep -h -E '^[a-zA-Z0-9_-]+:.*?# .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?# "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

.PHONY: install
install: # Install and setup qmk firmware
	@echo "Installing qmk firmware"
	./scripts/qmk_install

.PHONY: q8_setup
q8_setup: # Symlink custom keychron q8 iso encoder layout
	rm -rf ${HOME}/qmk_firmware/keyboards/keychron/q8/iso_encoder/keymaps/hrvthzslt
	ln -s ${PWD}/keyboards/keychron/q8/iso_encoder/keymaps/hrvthzslt ${HOME}/qmk_firmware/keyboards/keychron/q8/iso_encoder/keymaps/hrvthzslt

.PHONY: q8_compile
q8_compile: # Compile custom keychron q8 iso encoder layout
	qmk compile -kb keychron/q8/iso_encoder -km hrvthzslt

.PHONY: q8_flash
q8_flash: # Flash custom keychron q8 iso encoder layout
	qmk flash -kb keychron/q8/iso_encoder -km hrvthzslt