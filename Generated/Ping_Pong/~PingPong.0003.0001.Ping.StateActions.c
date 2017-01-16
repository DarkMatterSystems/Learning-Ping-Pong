
#include "~PingPong.0000.0000.Header.h"


/* Ping State Actions */

void adm_state_action_ping_sending(
    adm_ent_ping_typ * ent_ping)
{
    /* Entity Objects */
    adm_ent_pong_typ * ent_pong_0000000001;

    /* Relationship Relations */
    adm_rel_ping_signals_pong_typ * rel_ping_signals_pong_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_ping_sending");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_ping(
        ent_ping,
        1, 40, 45);

    rel_ping_signals_pong_0000000001 = ent_ping->rel_signals_pong_head;

    ent_pong_0000000001 = rel_ping_signals_pong_0000000001->ent_pong;

    /* CaseSelection */

    if (
        (
            (
                ent_ping->atb_count < ent_ping->atb_limit
            )
        )) {

        /* Assignment - Evaluation */

        ent_ping->atb_count =
            +(
                +(
                    +ent_ping->atb_count
                    +
                    1
                )
            );

        if (
            ent_ping->atb_count < ADM_TYPE_MINIMUM_INDEX ||
            ent_ping->atb_count > ADM_TYPE_MAXIMUM_INDEX) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                1, 49, 72,
                "Ping",
                ent_ping->identity,
                "Count",
                adm_sim_lib_itoa(ent_ping->atb_count));
        }

        /* Template */

        adm_write_newline();
        adm_write_str("Ping Pinged (");
        adm_write_int(ent_ping->atb_count);
        adm_write_str(")");

        /* GenerateEvent */

        adm_send_event_ping_wait(
            ent_ping,
            ent_ping,
            1, 57, 61);

        /* GenerateEvent */

        adm_send_event_pong_go(
            ent_ping,
            ent_pong_0000000001,
            1, 58, 61);

    } else {

        /* GenerateEvent */

        adm_send_event_ping_die(
            ent_ping,
            ent_ping,
            1, 61, 57);

        /* GenerateEvent */

        adm_send_event_pong_die(
            ent_ping,
            ent_pong_0000000001,
            1, 62, 57);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_ping_sending");
    #endif
}

void adm_state_action_ping_terminated(
    adm_ent_ping_typ * ent_ping)
{
    /* Entity Objects */
    adm_ent_pong_typ * ent_pong_0000000001;

    /* Relationship Relations */
    adm_rel_ping_signals_pong_typ * rel_ping_signals_pong_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_ping_terminated");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_ping(
        ent_ping,
        1, 80, 45);

    rel_ping_signals_pong_0000000001 = ent_ping->rel_signals_pong_head;

    ent_pong_0000000001 = rel_ping_signals_pong_0000000001->ent_pong;

    /* Unrelate */

    adm_kill_relation_ping_signals_pong(
        ent_ping,
        rel_ping_signals_pong_0000000001,
        1, 83, 49);

    /* Template */

    adm_write_newline();
    adm_write_str("Ping Terminated");

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_ping_terminated");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */