
## Projeto de Monitoramento Ambiental para Agricultura

### Objetivo
Desenvolvimento de um sistema para monitorar e controlar o ambiente em aplicações agrícolas, otimizando a irrigação e a segurança da propriedade. O sistema utiliza sensores para coletar dados sobre temperatura, umidade, nível de água, luminosidade e movimento, permitindo a tomada de decisões automatizadas e a geração de alertas.

### Sensores
* **DHT22:** Mede temperatura e umidade relativa do ar, mede constantemente a umidade e temperatura do ambiente, enviando alertas ou tomando ações automáticas para aumentar ou diminuir a irrigação dependendo das condições.
* **HC-SR04:** Verifica o nível de água nos tanques e aciona a irrigação apenas quando o nível está adequado, evitando desperdício de água.
* **PIR:** Detecta invasões de animais ou pessoas em áreas restritas da fazenda, ativando alarmes ou sistemas de segurança.
* **LDR:** Mede a quantidade de luz solar recebida e ajusta a irrigação automaticamente, diminuindo a quantidade de água em dias mais ensolarados e aumentando em dias nublados.

### Configuração e Execução no Wokwi e ESP32
**Wokwi:**
1. **Crie um novo projeto:** Acesse a plataforma Wokwi.
2. **Adicione componentes:** Arraste os componentes para a área de trabalho.
3. **Conecte componentes:** Conecte os pinos de acordo com o diagrama esquemático.
4. **Cole o código:** Copie e cole o código do seu projeto.
5. **Simule:** Clique em "Simular" para executar e visualizar os resultados.

### Instruções de Instalação e Dependências
**Bibliotecas:**
* **DHT:** Para leitura de dados de sensores de temperatura e umidade da família DHT.

**Software:**
* **Wokwi:** Simulador online para prototipagem rápida.
site: https://wokwi.com/

### [Adicione aqui outras seções relevantes, como:]
* **Diagrama esquemático:** 
![diagram-wokwi](<Captura de tela de 2024-11-05 22-20-02.png>)




Uma imagem representando a conexão dos componentes.
* **Código:** O código completo do projeto, formatado em Markdown ou em um bloco de código.
* **Resultados:** Exemplos de dados coletados e gráficos.
* **Próximos passos:** Planos para futuras melhorias ou funcionalidades.
* **Contribuições:** Informações sobre como contribuir para o projeto.

**Dicas:**
* Utilize o Markdown para formatar o texto com títulos, listas, código e imagens.
* Organize o README de forma clara e concisa, facilitando a compreensão do projeto.
* Inclua links para recursos externos, como a documentação da biblioteca DHT ou a plataforma Wokwi.
* Use imagens para ilustrar o projeto e tornar o README mais visualmente atraente.

**Exemplo de bloco de código:**
```c++
// Exemplo de código utilizando a biblioteca DHT
#include <DHT.h>

// ...