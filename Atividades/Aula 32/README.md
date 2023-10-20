# Exercício aula 32

## Classe Data
### Utilizando a função "formatar"
> Formatos disponíveis:

| Tipo | Exemplo saída |
| ----- | ----------------- |
| SHORT | 19/10/23 |
| MEDIUM | 19/10/2023 |
| LONG | 19 de Outubro de 2023 |
| FULL | Quarta-feira, 19 de Outubro de 2023 |


> Exemplo de utilização

```
int  main(void) {
	// Instanciando uma data
	Data  data(31, 5, 2023);
	
	// Formatando a data 
	cout  <<  data.formatar(data, data.SHORT) <<  endl;
	cout  <<  data.formatar(data, data.MEDIUM) <<  endl;
	cout  <<  data.formatar(data, data.LONG) <<  endl;
	cout  <<  data.formatar(data, data.FULL) <<  endl;

	cout  <<  endl;
	return  0;
}

/**
* Saída:
* 
* 19/10/23
* 19/10/2023
* 19 de Outubro de 2023
* Quarta-feira, 19 de Outubro de 2023 
*/
```
Créditos: @thales-assis | # **[Calcular-Dia-da-Semana.cpp](https://gist.github.com/thales-assis/f1d8dc868ae6cc971bd6c87c2aec1118)**
