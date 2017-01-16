
#include "~PingPong.0000.0000.Header.h"


/* Pong Dispatcher */

/* Dispatcher */

void adm_dispatcher_pong(
    void)
{
    adm_pool_target_pong_typ * pool_target_pong;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_pong");
    #endif

    pool_target_pong = adm_find_away_target_event_pong();

    adm_dispatch_state_action_pong(pool_target_pong);

    adm_dispatch_home_pool_pong();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_pong");
    #endif
}


/* Dispatch Home Pool */

void adm_dispatch_home_pool_pong(
    void)
{
    adm_pool_target_pong_typ * pool_target_pong;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_pong");
    #endif

    while (adm_entity_system.ent_pong.home_pool_head != NULL) {

        pool_target_pong = adm_find_home_target_event_pong();

        adm_dispatch_state_action_pong(pool_target_pong);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_pong");
    #endif
}


/* Find Home Target Event */

adm_pool_target_pong_typ * adm_find_home_target_event_pong(
    void)
{
    adm_pool_target_pong_typ * pool_target_pong;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_pong");
    #endif

    pool_target_pong = adm_entity_system.ent_pong.home_pool_head;

    adm_entity_system.ent_pong.home_pool_head = pool_target_pong->next;

    if (adm_entity_system.ent_pong.home_pool_head == NULL) {

        adm_entity_system.ent_pong.home_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_pong");
    #endif

    return (pool_target_pong);
}


/* Find Away Target Event */

adm_pool_target_pong_typ * adm_find_away_target_event_pong(
    void)
{
    adm_pool_target_pong_typ * pool_target_pong;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_pong");
    #endif

    pool_target_pong = adm_entity_system.ent_pong.away_pool_head;

    adm_entity_system.ent_pong.away_pool_head = pool_target_pong->next;

    if (adm_entity_system.ent_pong.away_pool_head == NULL) {

        adm_entity_system.ent_pong.away_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_pong");
    #endif

    return (pool_target_pong);
}


/* Dispatch State Action */

void adm_dispatch_state_action_pong(
    adm_pool_target_pong_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_pong");
    #endif

    if (pool_target->ent_pong != NULL) {

        adm_object_existent_pong(
            pool_target->ent_pong,
            pool_target->error_location.file,
            pool_target->error_location.line,
            pool_target->error_location.rank);
    }

    switch (pool_target->evente) {

        /* Dynamic Events */

        case ADM_EVENT_PONG_GO :

            switch ((pool_target->ent_pong)->status) {

                case ADM_STATUS_PONG_ACTIVATE :

                    adm_sim_display_state_pong_sending(pool_target);

                    (pool_target->ent_pong)->status = ADM_STATUS_PONG_SENDING;

                    adm_state_action_pong_sending(
                        pool_target->ent_pong);

                break;

                case ADM_STATUS_PONG_SENDING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Pong",
                        (pool_target->ent_pong)->identity,
                        "Event:Go",
                        "State:Sending");

                break;

                case ADM_STATUS_PONG_WAITING :

                    adm_sim_display_state_pong_sending(pool_target);

                    (pool_target->ent_pong)->status = ADM_STATUS_PONG_SENDING;

                    adm_state_action_pong_sending(
                        pool_target->ent_pong);

                break;

                case ADM_STATUS_PONG_TERMINATED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Pong",
                        (pool_target->ent_pong)->identity,
                        "Event:Go",
                        "State:Terminated");

                break;
            }

        break;

        case ADM_EVENT_PONG_WAIT :

            switch ((pool_target->ent_pong)->status) {

                case ADM_STATUS_PONG_ACTIVATE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Pong",
                        (pool_target->ent_pong)->identity,
                        "Event:Wait",
                        "State:Activate");

                break;

                case ADM_STATUS_PONG_SENDING :

                    adm_sim_display_state_pong_waiting(pool_target);

                    (pool_target->ent_pong)->status = ADM_STATUS_PONG_WAITING;

                break;

                case ADM_STATUS_PONG_WAITING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Pong",
                        (pool_target->ent_pong)->identity,
                        "Event:Wait",
                        "State:Waiting");

                break;

                case ADM_STATUS_PONG_TERMINATED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Pong",
                        (pool_target->ent_pong)->identity,
                        "Event:Wait",
                        "State:Terminated");

                break;
            }

        break;

        /* Deletion Events */

        case ADM_EVENT_PONG_DIE :

            switch ((pool_target->ent_pong)->status) {

                case ADM_STATUS_PONG_ACTIVATE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Pong",
                        (pool_target->ent_pong)->identity,
                        "Event:Die",
                        "State:Activate");

                break;

                case ADM_STATUS_PONG_SENDING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Pong",
                        (pool_target->ent_pong)->identity,
                        "Event:Die",
                        "State:Sending");

                break;

                case ADM_STATUS_PONG_WAITING :

                    adm_sim_display_state_pong_terminated(pool_target);

                    adm_state_action_pong_terminated(
                        pool_target->ent_pong);

                    adm_kill_object_pong(
                        NULL,
                        pool_target->ent_pong,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank);

                break;

                case ADM_STATUS_PONG_TERMINATED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Pong",
                        (pool_target->ent_pong)->identity,
                        "Event:Die",
                        "State:Terminated");

                break;
            }

        break;
    }

    adm_deallocate_memory(pool_target);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_pong");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */