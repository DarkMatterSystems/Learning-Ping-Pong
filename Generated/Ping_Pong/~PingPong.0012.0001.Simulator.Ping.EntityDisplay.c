
#include "~PingPong.0000.0000.Header.h"


/* Ping Simulator Display Entity */

void adm_sim_display_entity_ping(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_ping_typ * ent_ping;

    adm_sim_width_ping_typ width_ping;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_ping");
    #endif

    width_ping.identity = strlen("Identity");
    width_ping.status = strlen("Status");
    width_ping.atb_count = strlen("Count");
    width_ping.atb_limit = strlen("Limit");

    ent_ping = adm_entity_system.ent_ping.live_list_head;

    while (ent_ping != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_ping->identity);
        if (width > width_ping.identity) width_ping.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%s", adm_sim_status_ping[ent_ping->status]);
        if (width > width_ping.status) width_ping.status = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_ping->atb_count);
        if (width > width_ping.atb_count) width_ping.atb_count = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_ping->atb_limit);
        if (width > width_ping.atb_limit) width_ping.atb_limit = width;

        ent_ping = ent_ping->next;
    }

    printf(NEWLINE);
    printf("Ping:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_ping.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_ping.status, "Status");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_ping.atb_count, "Count");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_ping.atb_limit, "Limit");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_ping.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_ping.status);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_ping.atb_count);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_ping.atb_limit);

    ent_ping = adm_entity_system.ent_ping.live_list_head;

    while (ent_ping != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_ping.identity, ent_ping->identity);
        printf(ADM_SIM_COLUMN_GAP);

        switch (ent_ping->status) {
            case ADM_STATUS_PING_ACTIVATE :
                printf("%-*s", width_ping.status, "Activate");
            break;
            case ADM_STATUS_PING_SENDING :
                printf("%-*s", width_ping.status, "Sending");
            break;
            case ADM_STATUS_PING_WAITING :
                printf("%-*s", width_ping.status, "Waiting");
            break;
            case ADM_STATUS_PING_TERMINATED :
                printf("%-*s", width_ping.status, "Terminated");
            break;
            default :
                printf("%-*s", width_ping.status, "ERROR");
            break;
        }

        printf(ADM_SIM_COLUMN_GAP);
        printf("%*d", width_ping.atb_count, ent_ping->atb_count);
        printf(ADM_SIM_COLUMN_GAP);
        printf("%*d", width_ping.atb_limit, ent_ping->atb_limit);

        ent_ping = ent_ping->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_ping");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */