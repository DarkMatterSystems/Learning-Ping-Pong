
#include "~PingPong.0000.0000.Header.h"


/* Pong Data Access */

/* Make Entity Object */

adm_ent_pong_typ * adm_make_object_pong(
    adm_sta_pong_typ status)
{
    adm_ent_pong_typ * ent_pong;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_pong");
    #endif

    if (adm_entity_system.ent_pong.dead_list_head != NULL) {

        ent_pong = adm_entity_system.ent_pong.dead_list_head;

        if (adm_entity_system.ent_pong.dead_list_head == ent_pong) {

            adm_entity_system.ent_pong.dead_list_head = ent_pong->next;

        } else {

            (ent_pong->back)->next = ent_pong->next;
        }

        if (adm_entity_system.ent_pong.dead_list_tail == ent_pong) {

            adm_entity_system.ent_pong.dead_list_tail = ent_pong->back;

        } else {

            (ent_pong->next)->back = ent_pong->back;
        }

    } else {

        ent_pong = (adm_ent_pong_typ*)adm_allocate_memory(sizeof(adm_ent_pong_typ));
    }

    ent_pong->identity = ++adm_entity_system.ent_pong.tote;

    ent_pong->unique  = FALSE;
    ent_pong->deleted = FALSE;
    ent_pong->marked  = FALSE;
    ent_pong->status  = status;

    ent_pong->rel_replies_ping_head = NULL;
    ent_pong->rel_replies_ping_tail = NULL;

    ent_pong->back = NULL;
    ent_pong->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_pong");
    #endif

    return (ent_pong);
}


/* Bind Entity Object */

void adm_bind_object_pong(
    adm_ent_pong_typ * ent_pong,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_pong");
    #endif

    adm_object_existent_pong(
        ent_pong,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_pong.live_list_head == NULL) {

        ent_pong->back = NULL;

        adm_entity_system.ent_pong.live_list_head = ent_pong;

    } else {

        ent_pong->back = adm_entity_system.ent_pong.live_list_tail;

        (adm_entity_system.ent_pong.live_list_tail)->next = ent_pong;
    }

    ent_pong->next = NULL;

    adm_entity_system.ent_pong.live_list_tail = ent_pong;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_pong");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_pong(
    void * source_object,
    adm_ent_pong_typ * ent_pong,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_pong");
    #endif

    adm_object_existent_pong(
        ent_pong,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_pong) {

        if (ent_pong->rel_replies_ping_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Pong",
                ent_pong->identity,
                "Replies",
                "Ping");
        }

        if (adm_entity_system.ent_pong.live_list_head == ent_pong) {

            adm_entity_system.ent_pong.live_list_head = ent_pong->next;

        } else {

            (ent_pong->back)->next = ent_pong->next;
        }

        if (adm_entity_system.ent_pong.live_list_tail == ent_pong) {

            adm_entity_system.ent_pong.live_list_tail = ent_pong->back;

        } else {

            (ent_pong->next)->back = ent_pong->back;
        }

        ent_pong->deleted = TRUE;

        if (adm_entity_system.ent_pong.dead_list_head == NULL) {

            ent_pong->back = NULL;

            adm_entity_system.ent_pong.dead_list_head = ent_pong;

        } else {

            ent_pong->back = adm_entity_system.ent_pong.dead_list_tail;

            (adm_entity_system.ent_pong.dead_list_tail)->next = ent_pong;
        }

        ent_pong->next = NULL;

        adm_entity_system.ent_pong.dead_list_tail = ent_pong;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Pong",
            ent_pong->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_pong");
    #endif
}


/* Link Entity Relations */

void adm_link_relation_pong_replies_ping(
    adm_ent_pong_typ * ent_source_pong,
    adm_ent_ping_typ * ent_target_ping,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_pong_replies_ping_typ * rel_pong_replies_ping;

    adm_base_boolean_typ ping_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_pong_replies_ping");
    #endif

    adm_object_existent_pong(
        ent_source_pong,
        error_file,
        error_line,
        error_rank);

    ping_not_found = TRUE;

    rel_pong_replies_ping = ent_source_pong->rel_replies_ping_head;

    while (
        ping_not_found &&
        rel_pong_replies_ping != NULL) {

        if (rel_pong_replies_ping->ent_ping == ent_target_ping) {

            ping_not_found = FALSE;
        }

        rel_pong_replies_ping = rel_pong_replies_ping->next;
    }

    if (ping_not_found) {

        rel_pong_replies_ping = (adm_rel_pong_replies_ping_typ*)
            adm_allocate_memory(sizeof(adm_rel_pong_replies_ping_typ));

        rel_pong_replies_ping->ent_ping = ent_target_ping;

        if (ent_source_pong->rel_replies_ping_head == NULL) {

            rel_pong_replies_ping->back = NULL;

            ent_source_pong->rel_replies_ping_head = rel_pong_replies_ping;

        } else {

            rel_pong_replies_ping->back = ent_source_pong->rel_replies_ping_tail;

            (ent_source_pong->rel_replies_ping_tail)->next = rel_pong_replies_ping;
        }

        rel_pong_replies_ping->next = NULL;

        ent_source_pong->rel_replies_ping_tail = rel_pong_replies_ping;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Pong",
            ent_source_pong->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_pong_replies_ping");
    #endif
}


/* Kill Entity Relations */

void adm_kill_relation_pong_replies_ping(
    adm_ent_pong_typ * ent_pong,
    adm_rel_pong_replies_ping_typ * rel_pong_replies_ping,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_pong_replies_ping");
    #endif

    adm_object_existent_pong(
        ent_pong,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_pong_replies_ping->next !=
        (adm_base_integer_typ)rel_pong_replies_ping->ent_ping) {

        if (ent_pong->rel_replies_ping_head != NULL) {

            if (ent_pong->rel_replies_ping_head == rel_pong_replies_ping) {

                ent_pong->rel_replies_ping_head = rel_pong_replies_ping->next;

            } else {

                (rel_pong_replies_ping->back)->next = rel_pong_replies_ping->next;
            }

            if (ent_pong->rel_replies_ping_tail == rel_pong_replies_ping) {

                ent_pong->rel_replies_ping_tail = rel_pong_replies_ping->back;

            } else {

                (rel_pong_replies_ping->next)->back = rel_pong_replies_ping->back;
            }

            adm_deallocate_memory(rel_pong_replies_ping);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Pong",
                ent_pong->identity,
                "Replies",
                "Ping");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Pong",
            ent_pong->identity,
            "Replies",
            "Ping");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_pong_replies_ping");
    #endif
}


/* Object Existent */

void adm_object_existent_pong(
    adm_ent_pong_typ * ent_pong,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_pong");
    #endif

    if (ent_pong->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Pong",
            ent_pong->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_pong");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */