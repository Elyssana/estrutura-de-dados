1 atividade) Questão 4.19 da página 148 do livro

2 atividade) Faça um programa de gerenciamento de uma fila de atendimento de banco, considerando que existe 3 tipos de clientes:

o com prioridade zero, que é uma pessoa que não é cliente do banco,

o com prioridade um, que é uma pessoa que é cliente do banco,

o com prioridade dois, que é uma pessoa que não é cliente do banco e que tem prioridade por lei no atendimento,

o com prioridade três, que é uma pessoa que é cliente do banco e que tem prioridade por lei no atendimento.

Seu programa deve prever um atendimento balanceado de modo que os clientes sejam atendidos em períodos balanceados, para que um cliente de prioridade baixa não fica aguardando indefinidamente. (dica para balancear, você deve encontrar o número de clientes de cada prioridade que deve ser atendido de forma intercalada. Lembre-se que este número de balanceamento se altera a cada entra e/ou sai da cliente na fila, para facilitar esta dinâmica, considere o recalculo do balanceamento a cada 4 novos acontecimentos de entrada e/ou saída)

3 atividade) Faça um programa de gerenciamento do estoque de produtos de uma fábrica com uma lista. Considerando que o registro dos produtos no estoque contenha as seguintes informações: código, descrição, marca, data de validade e quantidade. Espera-se com este programa poder listar na tela um relatório do estoque atual, incluir, retira e consultar produtos do estoque. Lembre-se que a operação de retirada deve priorizar a saída dos produtos mais antigos e só depois dos produtos mais novos, para evitar a perda de produto por prazo de validade.

(observação você vai precisar de uma struct para definir o produto, observe que como temos diferentes entradas de um mesmo produto é necessário que você subtraia a quantidade de produtos de uma entrada no estoque até que ela seja zero, sendo primeiro retirada as entradas com prazo de validade mais próximo e depois a com prazo de validade mais distante) 