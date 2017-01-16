
#include "~PingPong.0000.0000.Header.h"


/* Ping Dispatcher */

/* Dispatcher */

void adm_dispatcher_ping(
    void)
{
    adm_pool_target_ping_typ * pool_target_ping;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_ping");
    #endif

    pool_target_ping = adm_find_away_target_event_ping();

    adm_dispatch_state_action_ping(pool_target_ping);

    adm_dispatch_home_pool_ping();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_ping");
    #endif
}


/* Dispatch Home Pool */

void adm_dispatch_home_pool_ping(
    void)
{
    adm_pool_target_ping_typ * pool_target_ping;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_ping");
    #endif

    while (adm_entity_system.ent_ping.home_pool_head != NULL) {

        pool_target_ping = adm_find_home_target_event_ping();

        adm_dispatch_state_action_ping(pool_target_ping);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_ping");
    #endif
}


/* Find Home Target Event */

adm_pool_target_ping_typ * adm_find_home_target_event_ping(
    void)
{
    adm_pool_target_ping_typ * pool_target_ping;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_ping");
    #endif

    pool_target_ping = adm_entity_system.ent_ping.home_pool_head;

    adm_entity_system.ent_ping.home_pool_head = pool_target_ping->next;

    if (adm_entity_system.ent_ping.home_pool_head == NULL) {

        adm_entity_system.ent_ping.home_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_ping");
    #endif

    return (pool_target_ping);
}


/* Find Away Target Event */

adm_pool_target_ping_typ * adm_find_away_target_event_ping(
    void)
{
    adm_pool_target_ping_typ * pool_target_ping;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_ping");
    #endif

    pool_target_ping = adm_entity_system.ent_ping.away_pool_head;

    adm_entity_system.ent_ping.away_pool_head = pool_target_ping->next;

    if (adm_entity_system.ent_ping.away_pool_head == NULL) {

        adm_entity_system.ent_ping.away_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_ping");
    #endif

    return (pool_target_ping);
}


/* Dispatch State Action */

void adm_dispatch_state_action_ping(
    adm_pool_target_ping_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_ping");
    #endif

    if (pool_target->ent_ping != NULL) {

        adm_object_existent_ping(
            pool_target->ent_ping,
            pool_target->error_location.file,
            pool_target->error_location.line,
            pool_target->error_location.rank);
    }

    switch (pool_target->evente) {

        /* Dynamic Events */

        case ADM_EVENT_PING_GO :

            switch ((pool_target->ent_ping)->status) {

                case ADM_STATUS_PING_ACTIVATE :

                    adm_sim_display_state_ping_sending(pool_target);

                    (pool_target->ent_ping)->status = ADM_STATUS_PING_SENDING;

                    adm_state_action_ping_sending(
                        pool_target->ent_ping);

                break;

                case ADM_STATUS_PING_SENDING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Ping",
                        (pool_target->ent_ping)->identity,
                        "Event:Go",
                        "State:Sending");

                break;

                case ADM_STATUS_PING_WAITING :

                    adm_sim_display_state_ping_sending(pool_target);

                    (pool_target->ent_ping)->status = ADM_STATUS_PING_SENDING;

                    adm_state_action_ping_sending(
                        pool_target->ent_ping);

                break;

                case ADM_STATUS_PING_TERMINATED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Ping",
                        (pool_target->ent_ping)->identity,
                        "Event:Go",
                        "State:Terminated");

                break;
            }

        break;

        case ADM_EVENT_PING_WAIT :

            switch ((pool_target->ent_ping)->status) {

                case ADM_STATUS_PING_SENDING :

                    adm_sim_display_state_ping_waiting(pool_target);

                    (pool_target->ent_ping)->status = ADM_STATUS_PING_WAITING;

                break;

                case ADM_STATUS_PING_WAITING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Ping",
                        (pool_target->ent_ping)->identity,
                        "Event:Wait",
                        "State:Waiting");

                break;

                case ADM_STATUS_PING_TERMINATED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Ping",
                        (pool_target->ent_ping)->identity,
                        "Event:Wait",
                        "State:Terminated");

                break;
            }

        break;

        /* Deletion Events */

        case ADM_EVENT_PING_DIE :

            switch ((pool_target->ent_ping)->status) {

                case ADM_STATUS_PING_ACTIVATE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Ping",
                        (pool_target->ent_ping)->identity,
                        "Event:Die",
                        "State:Activate");

                break;

                case ADM_STATUS_PING_SENDING :

                    adm_sim_display_state_ping_terminated(pool_target);

                    adm_state_action_ping_terminated(
                        pool_target->ent_ping);

                    adm_kill_object_ping(
                        NULL,
                        pool_target->ent_ping,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank);

                break;

                case ADM_STATUS_PING_WAITING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Ping",
                        (pool_target->ent_ping)->identity,
                        "Event:Die",
                        "State:Waiting");

                break;

                case ADM_STATUS_PING_TERMINATED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Ping",
                        (pool_target->ent_ping)->identity,
                        "Event:Die",
                        "State:Terminated");

                break;
            }

        break;
    }

    adm_deallocate_memory(pool_target);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_ping");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */