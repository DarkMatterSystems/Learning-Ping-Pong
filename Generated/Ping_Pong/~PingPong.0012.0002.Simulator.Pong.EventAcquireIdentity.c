
#include "~PingPong.0000.0000.Header.h"


/* Simulator Pong Acquire Identity Event */

void adm_sim_acquire_identity_event_pong_go(
    void)
{
    adm_ent_pong_typ * ent_pong;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_pong_go");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_pong = adm_entity_system.ent_pong.live_list_head;

    while (
        entity_not_found &&
        ent_pong != NULL) {

        if (ent_pong->identity == identity) {

            adm_send_event_pong_go(
                NULL,
                ent_pong,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_pong = ent_pong->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_pong_go");
    #endif
}

void adm_sim_acquire_identity_event_pong_wait(
    void)
{
    adm_ent_pong_typ * ent_pong;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_pong_wait");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_pong = adm_entity_system.ent_pong.live_list_head;

    while (
        entity_not_found &&
        ent_pong != NULL) {

        if (ent_pong->identity == identity) {

            adm_send_event_pong_wait(
                NULL,
                ent_pong,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_pong = ent_pong->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_pong_wait");
    #endif
}

void adm_sim_acquire_identity_event_pong_die(
    void)
{
    adm_ent_pong_typ * ent_pong;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_pong_die");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_pong = adm_entity_system.ent_pong.live_list_head;

    while (
        entity_not_found &&
        ent_pong != NULL) {

        if (ent_pong->identity == identity) {

            adm_send_event_pong_die(
                NULL,
                ent_pong,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_pong = ent_pong->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_pong_die");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */