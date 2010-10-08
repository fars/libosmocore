#ifndef gsm0480_h
#define gsm0480_h

#include "msgb.h"

#define MAX_LEN_USSD_STRING	31

struct ussd_request {
	char text[MAX_LEN_USSD_STRING + 1];
	uint8_t transaction_id;
	uint8_t invoke_id;
};

int gsm0480_decode_ussd_request(const struct msgb *msg,
				struct ussd_request *request);

struct msgb *gsm0480_create_unstructuredSS_Notify(int alertPattern, const char *text);
struct msgb *gsm0480_create_notifySS(const char *text);

int gsm0480_wrap_invoke(struct msgb *msg, int op, int link_id);
int gsm0480_wrap_facility(struct msgb *msg);

#endif