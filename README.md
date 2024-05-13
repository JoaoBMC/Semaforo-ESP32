# Projeto Semaforo-ESP32
- Este é o primeiro projeto de uma série de estudos de programação [PRJT-7].

### Como Executar
Este projeto foi simulado no [Wi](https://wokwi.com/). Para simular lá, basta copiar o conteúdo do [diagram.ja](https://github.com/JoaoBMC/Semaforo-ESP32/blob/main/diagram.json) para o arquivo diagram.json no site e copiar o código [src/main.cpp](https://github.com/JoaoBMC/Semaforo-ESP32/blob/main/src/main.cpp) para o arquivo main.cpp no [Wi](https://wokwi.com/).

## Descrição
- Este projeto envolve a simulação de um sistema de semáforo para veículos e pedestres, incluindo um botão de acionamento e um contador regressivo que indica o tempo restante para a travessia dos pedestres.

## Sinal para Veículos (SV)
- LED Vermelho: Indica que os veículos devem parar e aguardar.
- LED Amarelo: Indica que a fase verde está prestes a terminar; os condutores devem parar, caso ainda não tenham atravessado o cruzamento.
- LED Verde: Indica que os veículos podem avançar com segurança.

   ### Funcionamento:
    - O LED verde permanecerá aceso por 30 segundos, após os quais se apagará. O LED amarelo será aceso por 3 segundos e, em seguida, se apagará. Então, o LED vermelho ficará aceso por 20 segundos. Após esse tempo, o LED apagará e o verde acenderá novamente, reiniciando o ciclo.

## Sinal para Pedestres (SP)
- LED Vermelho: Indica que os pedestres devem parar e aguardar.
- LED Verde: Indica que os pedestres podem atravessar a faixa de pedestres com segurança.
- Botão de Passagem: Permite que o pedestre solicite o fechamento do sinal para veículos para a passagem.
  
    ### Funcionamento:
    - O pedestre pode aguardar o ciclo do sinal para veículos passar para vermelho e o LED do Sinal para Pedestres ficar verde, ou pode acionar o Botão de Passagem para iniciar o fechamento (vermelho) do sinal para veículos e abrir (verde) o sinal para pedestres, mostrando uma contagem regressiva (de 20 segundos) de quanto tempo falta para o sinal para pedestres ficar vermelho e o para veículos ficar verde.
    
## Material
- ESP32
- LEDs
    - 2 Vermelhos
    - 1 Amarelo
    - 2 Verdes
- Display de 7 Segmentos com 2 Dígitos
- Botão tipo pushButton
- 15 resistores de 1k ohm

## Requisitos

### Funcionais
- Os LEDs Vermelho, Amarelo e Verde do sinal para veículos devem acender e apagar.
- Os LEDs Vermelho e Verde do Sinal para Pedestres devem acender e apagar.
- O Botão deve acionar o sinal para pedestres a qualquer momento.
- O Display deve mostrar o tempo restante para o término do sinal para pedestres.

### Não Funcionais
- Os LEDs do Sinal para veículos devem seguir a ordem: Verde → Amarelo → Vermelho → Verde.
- Os LEDs do Sinal para veículos devem ter os seguintes tempos:
    - Verde: 30 segundos
    - Amarelo: 2 segundos
    - Vermelho: 20 segundos
- O contador deve estar desligado caso não seja acionado pelo pedestre.

## Esquemático
 
![Esquemático projeto PRJT-7](https://github.com/JoaoBMC/Semaforo-ESP32/assets/64325336/bbca8b85-76b6-4fe9-843d-d67d4960e66f)

| Componente | GPIO |
| --- | --- |
| VERMELHO (SV) | 15 |
| AMARELO (SV) | 2 |
| VERDE (SV) | 0 |
| BOTÃO (SP) | 4 |
| VERMELHO (SP) | 16 |
| VERDE (SP) | 17 |
| DISPLAY DG 01 (SP) | 7 |
| DISPLAY DG 02 (SP) | 8 |
| DISPLAY A (SP) | 5 |
| DISPLAY B (SP) | 18 |
| DISPLAY C (SP) | 19 |
| DISPLAY D (SP) | 21 |
| DISPLAY E (SP) | 22 |
| DISPLAY F (SP) | 23 |
| DISPLAY G (SP) | 13 |
| DISPLAY DP (SP) | 12 |

### Display de 7 Segmentos com 2 dígitos (Esquemático)
![Esquemático display 7 seg 2 dígitos PRJT-7](https://github.com/JoaoBMC/Semaforo-ESP32/assets/64325336/3520efa6-7457-4df1-9356-5bf1635797de)
