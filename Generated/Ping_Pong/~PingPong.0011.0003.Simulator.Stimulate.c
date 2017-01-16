
#include "~PingPong.0000.0000.Header.h"


/* System Stimulate */

void adm_sim_simulate(
    void)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_simulate");
    #endif

    if (adm_sim_err_success) {

        while (
            adm_entity_system.ent_ping.away_pool_head != NULL ||
            adm_entity_system.ent_pong.away_pool_head != NULL) {

            adm_scheduler_dom_pinger();
        }

        adm_integrity_check();
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_simulate");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */