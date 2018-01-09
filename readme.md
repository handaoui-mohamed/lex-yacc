```
ECOLE NATIONALE SUPEREURE EN INFORMATIQUE
```
TP-COMPIL 1 / 1 2CS

## COMPILATION PROJET 2017 /20 18

# Utilisation de LEX et YACC pour l’évaluation et génération d’une

# forme intermédiaire d’une expression arithmétique

## Partie A.

 Dans cette partie du projet, il est demandé de développer un analyseur syntaxique d’une
expression arithmétique en utilisant LEX et YACC. Les opérandes sont des nombres entiers ou
flottants. Les erreurs syntaxiques et lexicales devront être signalées par des messages
significatifs. La reprise sur erreur est facultative dans cette partie du projet. L’expression en
entrée, est lue directement à partir de la ligne de commande ou à partir d’un fichier d’entrée.

## Partie B.

 Dans cette partie du projet, il s’agit de compléter le travail effectué dans la partie A pour
évaluer l’expression arithmétique donnée en entrée si cette dernière est syntaxiquement
correcte. Des fonctions supplémentaires souvent utilisées dans les évaluateurs d’expressions
seront inclus dans votre évaluateur. Ces fonctions vous seront communiquées en temps
opportun.

 Rajout des fonctions somme, produit, variance, écart-type avec imbrications. Exemple
d’évaluation : 5 + 3 * somme(4, somme(5,7,8), variance(1,1+1, moyenne(2,4),4,6-2))

## Partie C.

 Dans cette partie du projet les opérandes ne sont pas connus durant la phase de compilation
(exemple : a*(b+c)-d/e). Il est demandé, si l’expression en entrée est syntaxiquement correcte,
de générer une forme intermédiaire sous forme de quadruplets qui une fois exécuté donnera le
résultat de l’expression donné au départ. LEX et YACC seront également utilisés.

 Rajout des fonctions somme, produit, variance, écart-type avec imbrications. Exemple
d’évaluation : a + b * somme(c, somme(d,e,f), variance(a,b, c,d,e))


