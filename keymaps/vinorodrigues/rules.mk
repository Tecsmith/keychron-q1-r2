VIA_ENABLE = yes
MOUSEKEY_ENABLE = no
DIP_SWITCH_ENABLE = yes

ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
    SRC += rgb_matrix_keymap.c
endif
