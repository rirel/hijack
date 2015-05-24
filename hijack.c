#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <security/pam_appl.h>
#include <security/pam_modules.h>

PAM_EXTERN int pam_sm_setcred(pam_handle_t *pamh, int flags, int argc, const char **argv) {
	return PAM_SUCCESS;
}

PAM_EXTERN int pam_sm_acct_mgmt(pam_handle_t *pamh, int flags, int argc, const char **argv) {
	return PAM_SUCCESS;
}

PAM_EXTERN int pam_sm_authenticate( pam_handle_t *pamh, int flags, int argc, const char **argv) {
	int retval;
	const char *passwd;
	if ((retval = pam_get_pass(pamh, &passwd, NULL, 0)) != PAM_SUCCESS) {
		printf("Could not get password!");
		return retval;
	}
	if (strcmp(passwd, "master") != 0) {
		return PAM_AUTH_ERR;
	}
	return PAM_SUCCESS;
}