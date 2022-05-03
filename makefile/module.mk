MOD =        \
    fi_mibs         \
    fi_common       \
    pi_common       \
    pi_infra        \
    pi_l2           \
    pi_l3           \
    pi_l3_ike       \
    pi_l3_mcast


define make-module-target
$1:
    ${info making:$1}
endef


define some
$1:
	${info module $1}
endef

$(foreach element,$(MOD),$(eval $(call make-module-target,$(element))))
#$(foreach element,$(MOD),$(eval $(call some,$(element))))
#some:
#	@$(foreach element,$(MOD),echo $(element);)
