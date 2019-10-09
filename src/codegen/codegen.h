#define HSM_NAME_LEN (256)

struct CODEGEN_INDATA_ST {
	char name[HSM_NAME_LEN];
	int next;
};

struct CODEGEN_INDATA_EV {
	char name[HSM_NAME_LEN];
};
