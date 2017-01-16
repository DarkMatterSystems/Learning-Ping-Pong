
#include "~PingPong.0000.0000.Header.h"


/* Domain - Initialisation */

void adm_initialisation_pinger(
    void)
{
    /* Declare Objects */

    /* Ping */
    adm_ent_ping_typ * ent_ping_0000000001;

    /* Pong */
    adm_ent_pong_typ * ent_pong_0000000002;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_INITIALISATION, "adm_initialisation_pinger");
    #endif

    /* Entity System */

    adm_entity_system.ent_ping.tote = 0;
    adm_entity_system.ent_pong.tote = 0;

    adm_entity_system.ent_ping.live_list_head = NULL;
    adm_entity_system.ent_pong.live_list_head = NULL;

    adm_entity_system.ent_ping.live_list_tail = NULL;
    adm_entity_system.ent_pong.live_list_tail = NULL;

    adm_entity_system.ent_ping.dead_list_head = NULL;
    adm_entity_system.ent_pong.dead_list_head = NULL;

    adm_entity_system.ent_ping.dead_list_tail = NULL;
    adm_entity_system.ent_pong.dead_list_tail = NULL;

    adm_entity_system.ent_ping.home_pool_head = NULL;
    adm_entity_system.ent_pong.home_pool_head = NULL;

    adm_entity_system.ent_ping.home_pool_tail = NULL;
    adm_entity_system.ent_pong.home_pool_tail = NULL;

    adm_entity_system.ent_ping.away_pool_head = NULL;
    adm_entity_system.ent_pong.away_pool_head = NULL;

    adm_entity_system.ent_ping.away_pool_tail = NULL;
    adm_entity_system.ent_pong.away_pool_tail = NULL;


    /* Make Objects */

    /* Ping */
    ent_ping_0000000001 = adm_make_object_ping(ADM_STATUS_PING_ACTIVATE);

    /* Pong */
    ent_pong_0000000002 = adm_make_object_pong(ADM_STATUS_PONG_ACTIVATE);


    /* Object Fact Assignments */

    /* Ping */

    ent_ping_0000000001->atb_count = 0;
    ent_ping_0000000001->atb_limit = 5;


    /* Bind Objects */

    /* Ping */
    adm_bind_object_ping(
        ent_ping_0000000001,
        1, 150, 29);

    /* Pong */
    adm_bind_object_pong(
        ent_pong_0000000002,
        1, 160, 29);


    /* Link Relations */

    /* Ping */

    adm_link_relation_ping_signals_pong(
        ent_ping_0000000001,
        ent_pong_0000000002,
        1, 153, 29);

    /* Pong */

    adm_link_relation_pong_replies_ping(
        ent_pong_0000000002,
        ent_ping_0000000001,
        1, 162, 29);


    /* Generate Events */

    /* Ping */

    adm_send_event_ping_go(
        ent_ping_0000000001,
        ent_ping_0000000001, 
        1, 156, 29);


    /* Integrity Check */
    adm_integrity_check();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_INITIALISATION, "adm_initialisation_pinger");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */