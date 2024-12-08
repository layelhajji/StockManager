# 📦 Gestion des Stocks - Projet en C 🛒

## 🎯 Description
Ce projet implémente un système de gestion de stock pour les produits dans un magasin. Il permet à un administrateur de gérer les produits dans l'inventaire, avec des fonctionnalités d'ajout, modification, suppression, et recherche de produits. Un historique des actions est également enregistré pour un suivi détaillé des modifications effectuées sur les produits.

## 📋 Fonctionnalités
1. **➕ Ajouter un produit** : Permet d'ajouter un nouveau produit dans le stock avec sa référence, marque, prix et quantité.
2. **✏️ Modifier un produit** : Permet de modifier un produit existant, notamment le prix et la quantité.
3. **❌ Supprimer un produit** : Permet de supprimer un produit du stock.
4. **📜 Afficher les produits** : Affiche tous les produits disponibles dans le stock.
5. **🔍 Rechercher un produit** : Permet de rechercher un produit par sa référence.
6. **📝 Historique des actions** : Affiche l'historique des actions effectuées (ajouts, modifications, suppressions de produits).
7. **🚪 Quitter** : Quitte le programme.

## 🗂️ Structure du projet
- **produit.txt** : Contient les informations des produits (référence, marque, prix, stock).
- **historique.txt** : Contient un historique des actions effectuées (ajouts, modifications, suppressions de produits).
- **main.c** : Le fichier source principal contenant le programme.
- **s_produit** : Structure définissant un produit (référence, marque, prix, stock).
- **date** : Structure représentant la date d'une action.

## 🖥️ Prérequis
- Un compilateur C (par exemple, GCC).
- Le projet est conçu pour être exécuté sur des systèmes UNIX ou Windows avec un compilateur compatible.

