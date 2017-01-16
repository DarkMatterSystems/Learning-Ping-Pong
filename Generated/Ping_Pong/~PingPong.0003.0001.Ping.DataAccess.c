
#include "~PingPong.0000.0000.Header.h"


/* Ping Data Access */

/* Make Entity Object */

adm_ent_ping_typ * adm_make_object_ping(
    adm_sta_ping_typ status)
{
    adm_ent_ping_typ * ent_ping;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_ping");
    #endif

    if (adm_entity_system.ent_ping.dead_list_head != NULL) {

        ent_ping = adm_entity_system.ent_ping.dead_list_head;

        if (adm_entity_system.ent_ping.dead_list_head == ent_ping) {

            adm_entity_system.ent_ping.dead_list_head = ent_ping->next;

        } else {

            (ent_ping->back)->next = ent_ping->next;
        }

        if (adm_entity_system.ent_ping.dead_list_tail == ent_ping) {

            adm_entity_system.ent_ping.dead_list_tail = ent_ping->back;

        } else {

            (ent_ping->next)->back = ent_ping->back;
        }

    } else {

        ent_ping = (adm_ent_ping_typ*)adm_allocate_memory(sizeof(adm_ent_ping_typ));
    }

    ent_ping->identity = ++adm_entity_system.ent_ping.tote;

    ent_ping->unique  = FALSE;
    ent_ping->deleted = FALSE;
    ent_ping->marked  = FALSE;
    ent_ping->status  = status;

    ent_ping->rel_signals_pong_head = NULL;
    ent_ping->rel_signals_pong_tail = NULL;

    ent_ping->back = NULL;
    ent_ping->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_ping");
    #endif

    return (ent_ping);
}


/* Bind Entity Object */

void adm_bind_object_ping(
    adm_ent_ping_typ * ent_ping,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_ping");
    #endif

    adm_object_existent_ping(
        ent_ping,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_ping.live_list_head == NULL) {

        ent_ping->back = NULL;

        adm_entity_system.ent_ping.live_list_head = ent_ping;

    } else {

        ent_ping->back = adm_entity_system.ent_ping.live_list_tail;

        (adm_entity_system.ent_ping.live_list_tail)->next = ent_ping;
    }

    ent_ping->next = NULL;

    adm_entity_system.ent_ping.live_list_tail = ent_ping;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_ping");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_ping(
    void * source_object,
    adm_ent_ping_typ * ent_ping,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_ping");
    #endif

    adm_object_existent_ping(
        ent_ping,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_ping) {

        if (ent_ping->rel_signals_pong_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Ping",
                ent_ping->identity,
                "Signals",
                "Pong");
        }

        if (adm_entity_system.ent_ping.live_list_head == ent_ping) {

            adm_entity_system.ent_ping.live_list_head = ent_ping->next;

        } else {

            (ent_ping->back)->next = ent_ping->next;
        }

        if (adm_entity_system.ent_ping.live_list_tail == ent_ping) {

            adm_entity_system.ent_ping.live_list_tail = ent_ping->back;

        } else {

            (ent_ping->next)->back = ent_ping->back;
        }

        ent_ping->deleted = TRUE;

        if (adm_entity_system.ent_ping.dead_list_head == NULL) {

            ent_ping->back = NULL;

            adm_entity_system.ent_ping.dead_list_head = ent_ping;

        } else {

            ent_ping->back = adm_entity_system.ent_ping.dead_list_tail;

            (adm_entity_system.ent_ping.dead_list_tail)->next = ent_ping;
        }

        ent_ping->next = NULL;

        adm_entity_system.ent_ping.dead_list_tail = ent_ping;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Ping",
            ent_ping->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_ping");
    #endif
}


/* Link Entity Relations */

void adm_link_relation_ping_signals_pong(
    adm_ent_ping_typ * ent_source_ping,
    adm_ent_pong_typ * ent_target_pong,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_ping_signals_pong_typ * rel_ping_signals_pong;

    adm_base_boolean_typ pong_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_ping_signals_pong");
    #endif

    adm_object_existent_ping(
        ent_source_ping,
        error_file,
        error_line,
        error_rank);

    pong_not_found = TRUE;

    rel_ping_signals_pong = ent_source_ping->rel_signals_pong_head;

    while (
        pong_not_found &&
        rel_ping_signals_pong != NULL) {

        if (rel_ping_signals_pong->ent_pong == ent_target_pong) {

            pong_not_found = FALSE;
        }

        rel_ping_signals_pong = rel_ping_signals_pong->next;
    }

    if (pong_not_found) {

        rel_ping_signals_pong = (adm_rel_ping_signals_pong_typ*)
            adm_allocate_memory(sizeof(adm_rel_ping_signals_pong_typ));

        rel_ping_signals_pong->ent_pong = ent_target_pong;

        if (ent_source_ping->rel_signals_pong_head == NULL) {

            rel_ping_signals_pong->back = NULL;

            ent_source_ping->rel_signals_pong_head = rel_ping_signals_pong;

        } else {

            rel_ping_signals_pong->back = ent_source_ping->rel_signals_pong_tail;

            (ent_source_ping->rel_signals_pong_tail)->next = rel_ping_signals_pong;
        }

        rel_ping_signals_pong->next = NULL;

        ent_source_ping->rel_signals_pong_tail = rel_ping_signals_pong;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Ping",
            ent_source_ping->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_ping_signals_pong");
    #endif
}


/* Kill Entity Relations */

void adm_kill_relation_ping_signals_pong(
    adm_ent_ping_typ * ent_ping,
    adm_rel_ping_signals_pong_typ * rel_ping_signals_pong,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_ping_signals_pong");
    #endif

    adm_object_existent_ping(
        ent_ping,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_ping_signals_pong->next !=
        (adm_base_integer_typ)rel_ping_signals_pong->ent_pong) {

        if (ent_ping->rel_signals_pong_head != NULL) {

            if (ent_ping->rel_signals_pong_head == rel_ping_signals_pong) {

                ent_ping->rel_signals_pong_head = rel_ping_signals_pong->next;

            } else {

                (rel_ping_signals_pong->back)->next = rel_ping_signals_pong->next;
            }

            if (ent_ping->rel_signals_pong_tail == rel_ping_signals_pong) {

                ent_ping->rel_signals_pong_tail = rel_ping_signals_pong->back;

            } else {

                (rel_ping_signals_pong->next)->back = rel_ping_signals_pong->back;
            }

            adm_deallocate_memory(rel_ping_signals_pong);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Ping",
                ent_ping->identity,
                "Signals",
                "Pong");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Ping",
            ent_ping->identity,
            "Signals",
            "Pong");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_ping_signals_pong");
    #endif
}


/* Object Existent */

void adm_object_existent_ping(
    adm_ent_ping_typ * ent_ping,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_ping");
    #endif

    if (ent_ping->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Ping",
            ent_ping->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_ping");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */