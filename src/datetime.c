/**
 * @file datetime.c
 * @author ruilagarto-dev
 * @brief
 * 
 * @version 1
 * @date 2025-05-14
 */
#include "datetime.h"
#include "stringWrap.h"

#include <stdio.h>
#include <string.h>


/**
 * @brief 
 * [PT/EN] Cria um DateTime com a data/hora atual / Creates a DateTime with the current date and time
 * 
 * @return 
 * [PT/EN] Uma instância de DateTime / A DateTime struct instance
 */
DateTime createDateTime(){
    DateTime dt = {0};
    updateDateTime(%dt);
    return dt;
}



/**
 * @brief 
 * [PT/EN] Cria um DateTime vazio (com valores a zero) / Creates an empty DateTime (zeroed values)
 * 
 * @return 
 * [PT/EN] Uma instância de DateTime / A DateTime struct instance
 */
DateTime createDateTime(){
    DateTime dt = {0};
    return dt;
}


/**
 * @brief 
 * [PT/EN] Atualiza o conteúdo de um DateTime para a data/hora atual / Updates a DateTime struct with the current date and time
 * 
 * @param dt 
 * [PT/EN] Ponteiro para a struct DateTime a ser atualizada / Pointer to the DateTime struct to be updated
 */
void updateDateTime(DateTime *dt){
    time_t now = time(NULL);
    struct tm *local = localtime(&now);

    if(dt == NULL){
        return;
    }

    dt->day = local->tm_mday;
    dt->month = local->tm_mon + 1;
    dt->year = local->tm_year + 1900;

    dt->hour = local->tm_hour;
    dt->min = local->tm_min;
    dt->sec = local->tm_sec;
}


/**
 * @brief 
 * [PT/EN] Converte um DateTime para uma string formatada / Converts a DateTime to a formatted string
 * 
 * @param strW 
 * [PT/EN] Ponteiro para struct StringWrap de destino / Pointer to target StringWrap struct
 * 
 * @param dt 
 * [PT/EN] Struct DateTime de origem / Source DateTime struct
 */
void dateTimeToStringWrap(StringWrap *strw, DateTime dt){
    snprintf(
        strW->text, 
        STRING_MAX_LEN, 
        "%02d/%02d/%04d %02d:%02d:%02d", 
        dt.day, dt.month, dt.year, 
        dt.hour, dt.min, dt.sec
    );
}