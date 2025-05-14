/**
 * @file datetime.h
 * @author ruilagarto-dev
 * 
 * @brief 
 * [PT] Interface para manipulação de datas e horas com base na struct DateTime.  
 * [EN] Interface for handling dates and times using the DateTime struct.
 * 
 * @version 1
 * @date 2025-05-14
 */
#pragma once

#include <time.h>
#include "stringWrap.h"


/**
 * @brief 
 * [PT/EN] Struct que representa data e hora / Struct representing date and time
 */
typedef struct datetime{
    int day, month, year;
    int hour, min, sec; 
} DateTime;


/**
 * @brief 
 * [PT/EN] Cria um DateTime com a data/hora atual / Creates a DateTime with current date and time
 * 
 * @return 
 * [PT/EN] Uma instância de DateTime / A DateTime struct instance
 */
DateTime createDateTime();


/**
 * @brief 
 * [PT/EN] Cria um DateTime vazio (valores a zero) / Creates an empty DateTime (zeroed values)
 * 
 * @return 
 * [PT/EN] Uma instância de DateTime / A DateTime struct instance
 */
DateTime createEmptyDateTime();


/**
 * @brief 
 * [PT/EN] Atualiza o conteúdo de um DateTime para a data/hora atual / Updates a DateTime struct with the current date and time
 * 
 * @param dt 
 * [PT/EN] Ponteiro para a struct DateTime a ser atualizada / Pointer to the DateTime struct to be updated
 */
void updateDateTime(DateTime *dt);


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
void dateTimeToStringWrap(StringWrap *strW, DateTime dt);