/* Copyright (c) 1997 Silicon Graphics, Inc. */

/* SCCSid "$SunId$ SGI" */

/*
 * Header for holodeck display drivers.
 */

				/* display requests */
#define DR_BUNDLE	1		/* bundle request */
#define DR_ATTEN	2		/* request for attention */
#define DR_SHUTDOWN	3		/* shutdown request */
#define DR_NEWSET	4		/* new bundle set */
#define DR_ADDSET	5		/* add to current set */
#define DR_DELSET	6		/* delete from current set */

				/* server responses */
#define DS_BUNDLE	7		/* computed bundle */
#define DS_ACKNOW	8		/* acknowledge request for attention */
#define DS_SHUTDOWN	9		/* end process and close connection */
#define DS_ADDHOLO	10		/* register new holodeck */
#define DS_STARTIMM	11		/* begin immediate bundle set */
#define DS_ENDIMM	12		/* end immediate bundle set */

/*
 * Normally, the server channel has priority, with the display process
 * checking it frequently for new data.  However, when the display process
 * makes a request for attention (DR_ATTEN), the server will finish its
 * current operations and flush its buffers, sending an acknowledge
 * message (DS_ACKNOW) when it's done.  This then allows the
 * display process to send a long request to the holodeck server.
 * Priority returns to normal after the following request.
 */

#ifndef BIGREQSIZ
#define BIGREQSIZ	512		/* big request size (bytes) */
#endif

typedef struct {
	int2	type;		/* message type */
	int4	nbytes;		/* number of additional bytes */
} MSGHEAD;		/* message head */