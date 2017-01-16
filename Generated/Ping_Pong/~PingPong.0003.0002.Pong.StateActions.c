
#include "~PingPong.0000.0000.Header.h"


/* Pong State Actions */

void adm_state_action_pong_sending(
    adm_ent_pong_typ * ent_pong)
{
    /* Entity Objects */
    adm_ent_ping_typ * ent_ping_0000000001;

    /* Relationship Relations */
    adm_rel_pong_replies_ping_typ * rel_pong_replies_ping_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_pong_sending");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_pong(
        ent_pong,
        1, 107, 45);

    rel_pong_replies_ping_0000000001 = ent_pong->rel_replies_ping_head;

    ent_ping_0000000001 = rel_pong_replies_ping_0000000001->ent_ping;

    /* Template */

    adm_write_newline();
    adm_write_str("Pong Pinged (");
    adm_write_int(ent_ping_0000000001->atb_count);
    adm_write_str(")");

    /* GenerateEvent */

    adm_send_event_ping_go(
        ent_pong,
        ent_ping_0000000001,
        1, 112, 49);

    /* GenerateEvent */

    adm_send_event_pong_wait(
        ent_pong,
        ent_pong,
        1, 113, 49);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_pong_sending");
    #endif
}

void adm_state_action_pong_terminated(
    adm_ent_pong_typ * ent_pong)
{
    /* Entity Objects */
    adm_ent_ping_typ * ent_ping_0000000001;

    /* Relationship Relations */
    adm_rel_pong_replies_ping_typ * rel_pong_replies_ping_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_pong_terminated");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_pong(
        ent_pong,
        1, 131, 45);

    rel_pong_replies_ping_0000000001 = ent_pong->rel_replies_ping_head;

    ent_ping_0000000001 = rel_pong_replies_ping_0000000001->ent_ping;

    /* Unrelate */

    adm_kill_relation_pong_replies_ping(
        ent_pong,
        rel_pong_replies_ping_0000000001,
        1, 134, 49);

    /* Template */

    adm_write_newline();
    adm_write_str("Pong Terminated");
    adm_write_newline();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_pong_terminated");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */