#pragma once

#include "list.h"
#include "linked_list.h"

namespace structures
{
	// implementacne tipy: 
	//  - namiesto triedy List<T> mozete v triede DoubleLinkedList<T> 
	//    zdedit jednostranne zretazeny zoznam (LinkedList<T>).
	//    ak tak urobite, mozete mnoho metod odstranit a prekryt iba tie, 
	//    ktore maju z pohladu obojsmerne zretazeneho zoznamu vyznam a
	//    zvysok nechat na predka.
	//  - nezabudnite si vytvorit triedu pre prvok obojstranne zretazeneho zoznamu.
	//    opat tento prvok mozete zdedit z prvku jednostranne zretazeneho zoznamu.
	//  - ak vyuzijete dedicnost, budete moct vyuzit predkove iteratory, 
	//    takze ich nebudete musiet implementovat.
	
    template<typename T>
    class DoubleLinkedListItem : public LinkedListItem<T>
    {
    public:
        /// <summary> Konstruktor. </summary>
        /// <param name = "data"> Data, ktore uchovava. </param>
        DoubleLinkedListItem(T data);

        /// <summary> Kopirovaci konstruktor. </summary>
        /// <param name = "other"> Prvok jednstranne zretazeneho zoznamu, z ktoreho sa prevezmu vlastnosti.. </param>
        DoubleLinkedListItem(DoubleLinkedListItem<T>& other);

        /// <summary> Destruktor. </summary>
        ~DoubleLinkedListItem();

        /// <summary> Getter nasledujuceho prvku zretazeneho zoznamu. </summary>
        /// <returns> Nasledujuci prvok zretazeneho zoznamu. </returns>
        DoubleLinkedListItem<T>* getPrevious();

        /// <summary> Setter nasledujuceho prvku zretazeneho zoznamu. </summary>
        /// <param name�= "next"> Novy nasledujuci prvok zretazeneho zoznamu. </param>
        void setPrevious(DoubleLinkedListItem<T>* previous);
    private:
        DoubleLinkedListItem<T>* previous_;
    };

    /// <summary> Obojstranne zretazeny zoznam. </summary>
    /// <typeparam name = "T"> Typ dat ukladanych v zozname. </typepram>
	template<typename T>
	class DoubleLinkedList : public LinkedList<T> 
	{
    public:
        /*/// <summary> Konstruktor. </summary>
        DoubleLinkedList();

        /// <summary> Kopirovaci konstruktor. </summary>
        /// <param name = "other"> DoubleLinkedList, z ktoreho sa prevezmu vlastnosti. </param>
        DoubleLinkedList(DoubleLinkedList<T>& other);

        /// <summary> Destruktor. </summary>
        ~DoubleLinkedList();

        /// <summary> Vrati pocet prvkov v zozname. </summary>
        /// <returns> Pocet prvkov v zozname. </returns>
        size_t size() override;

        /// <summary> Priradenie struktury. </summary>
        /// <param name = "other"> Struktura, z ktorej ma prebrat vlastnosti. </param>
        /// <returns> Adresa, na ktorej sa struktura nachadza. </returns>
        Structure& assign(Structure& other) override;

        /// <summary> Porovnanie struktur. </summary>
        /// <param name="other">Struktura, s ktorou sa ma tato struktura porovnat. </param>
        /// <returns>True ak su struktury zhodne typom aj obsahom. </returns>
        bool equals(Structure& other) override;

        /// <summary> Vrati adresou prvok na indexe. </summary>
        /// <param name = "index"> Index prvku. </param>
        /// <returns> Adresa prvku na danom indexe. </returns>
        /// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>
        T& at(int index) override;*/

        /// <summary> Prida prvok do zoznamu. </summary>
        /// <param name = "data"> Pridavany prvok. </param>
        void add(const T& data) override;

        /// <summary> Vlozi prvok do zoznamu na dany index. </summary>
        /// <param name = "data"> Pridavany prvok. </param>
        /// <param name = "index"> Index prvku. </param>
        /// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>
        /// <remarks> Ak je ako index zadana hodnota poctu prvkov (teda prvy neplatny index), metoda insert sa sprava ako metoda add. </remarks>
        void insert(const T& data, int index) override;

        /*/// <summary> Odstrani prvy vyskyt prvku zo zoznamu. </summary>
        /// <param name = "data"> Odstranovany prvok. </param>
        /// <returns> true, ak sa podarilo prvok zo zoznamu odobrat, false inak. </returns>
        bool tryRemove(const T& data) override;*/

        /// <summary> Odstrani zo zoznamu prvok na danom indexe. </summary>
        /// <param name = "index"> Index prvku. </param>
        /// <returns> Odstraneny prvok. </returns>
        /// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>
        T removeAt(int index) override;

       /* /// <summary> Vrati index prveho vyskytu prvku v zozname. </summary>
        /// <param name = "data"> Prvok, ktoreho index sa hlada. </param>
        /// <returns> Index prveho vyskytu prvku v zozname, ak sa prvok v zozname nenachadza, vrati -1. </returns>
        int getIndexOf(const T& data) override;

        /// <summary> Vymaze zoznam. </summary>
        void clear() override;

        /// <summary> Vrati skutocny iterator na zaciatok struktury </summary>
        /// <returns> Iterator na zaciatok struktury. </returns>
        /// <remarks> Zabezpecuje polymorfizmus. </remarks>
        Iterator<T>* getBeginIterator() override;

        /// <summary> Vrati skutocny iterator na koniec struktury </summary>
        /// <returns> Iterator na koniec struktury. </returns>
        /// <remarks> Zabezpecuje polymorfizmus. </remarks>
        Iterator<T>* getEndIterator() override;*/

    protected:
        /// <summary> Vrati prvok zoznamu na danom indexe. </summary>
        /// <param name = "index"> Pozadovany index. </summary>
        /// <returns> Prvok zoznamu na danom indexe. </param>
        /// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>
        DoubleLinkedListItem<T>* getItemAtIndex(int index);
	};
    /*
    template<typename T>
    inline DoubleLinkedList<T>::DoubleLinkedList()
    {
        //TODO Zadanie 2: DoubleLinkedList
        throw std::runtime_error("DoubleLinkedList<T>::DoubleLinkedList: Not implemented yet.");
    }
    
    template<typename T>
    inline DoubleLinkedList<T>::DoubleLinkedList(DoubleLinkedList<T>& other)
    {
        assign(other);
    }

    template<typename T>
    inline DoubleLinkedList<T>::~DoubleLinkedList()
    {
        //TODO Zadanie 2: DoubleLinkedList
        throw std::runtime_error("DoubleLinkedList<T>::~DoubleLinkedList: Not implemented yet.");
    }

    template<typename T>
    inline size_t DoubleLinkedList<T>::size()
    {
        //TODO Zadanie 2: DoubleLinkedList
        throw std::runtime_error("DoubleLinkedList<T>::size: Not implemented yet.");
    }

    template<typename T>
    inline Structure& DoubleLinkedList<T>::assign(Structure& other)
    {
        //TODO Zadanie 2: DoubleLinkedList
        throw std::runtime_error("DoubleLinkedList<T>::assign: Not implemented yet.");
    }

    template<typename T>
    inline bool DoubleLinkedList<T>::equals(Structure& other)
    {
        //TODO Zadanie 2: DoubleLinkedList
        throw std::runtime_error("DoubleLinkedList<T>::equals: Not implemented yet.");
    }

    template<typename T>
    inline T& DoubleLinkedList<T>::at(int index)
    {
        //TODO Zadanie 2: DoubleLinkedList
        throw std::runtime_error("DoubleLinkedList<T>::at: Not implemented yet.");
    }
*/
    template<typename T>
    inline void DoubleLinkedList<T>::add(const T& data)
    {
        DoubleLinkedListItem<T>* newDLLI = new DoubleLinkedListItem<T>(data);
        if (size_ == 0) {
            first_ = newDLLI;
        }
        else {
            last_->setNext(newDLLI);
            newDLLI->setPrevious(dynamic_cast<DoubleLinkedListItem<T>*>(last_));
        }
        last_ = newDLLI;
        size_++;
    }

    template<typename T>
    inline void DoubleLinkedList<T>::insert(const T& data, int index)
    {
        if (index == size_) {
            add(data);
        }
        else {
            structures::Utils::rangeCheckExcept(index, size_, "Invalid index");
            auto newDLLI = new DoubleLinkedListItem<T>(data);
            if (index == 0) {
                newDLLI->setNext(first_);
                first_->setPrevious(newDLLI);
                first_ = newDLLI;
            }
            else {
                auto prev = getItemAtIndex(index - 1);
                newDLLI->setNext(prev->getNext());
                newDLLI->setPrevious(prev);
                prev->setNext(newDLLI);
                newDLLI->getNext()->setPrevious(newDLLI);
            }
            size_++;
        }
    }
    /*
    template<typename T>
    inline bool DoubleLinkedList<T>::tryRemove(const T& data)
    {
        //TODO Zadanie 2: DoubleLinkedList
        throw std::runtime_error("DoubleLinkedList<T>::tryRemove: Not implemented yet.");
    }
    */
    template<typename T>
    inline T DoubleLinkedList<T>::removeAt(int index)
    {
        DoubleLinkedListItem<T>* delItem = nullptr;
        Utils::rangeCheckExcept(index, size_, "Invalid Index");
        if (index == 0) {
            delItem = dynamic_cast<DoubleLinkedListItem<T>*>(first_);
            first_->getNext()->setPrevious(nullptr);
            first_ = first_->getNext();
            if (last_ == delItem) {
                last_ = nullptr;
            }
        }
        else {
            //DoubleLinkedListItem<T>* prev = getItemAtIndex(index - 1);
            delItem = getItemAtIndex(index);
            delItem->getPrevious()->setNext(delItem->getNext());
            delItem->getNext()->setPrevious(delItem->getPrevious());
            if (last_ == delItem) {
                last_ = delItem->getPrevious();
            }
        }
        T result = delItem->accessData();
        delItem->setPrevious(nullptr);
        delItem->setNext(nullptr);
        delete delItem;
        size_--;
        return result;
    }

    template<typename T>
    inline DoubleLinkedListItem<T>* DoubleLinkedList<T>::getItemAtIndex(int index)
    {
        if (index == size_ - 1) {
            return last_;
        }
        else {
            auto current = nullptr;
            if (index < size_ / 2) {
                current = first_
                for (int i = 0; i < index; i++)
                {
                    current = current->getNext();
                }
            }
            else {
                current = last_;
                for (int i = 0; i < index; i++)
                {
                    current = current->getPrevious();
                }
            }
            return current;
        }
    }
/*
    template<typename T>
    inline int DoubleLinkedList<T>::getIndexOf(const T& data)
    {
        //TODO Zadanie 2: DoubleLinkedList
        throw std::runtime_error("DoubleLinkedList<T>::getIndexOf: Not implemented yet.");
    }

    template<typename T>
    inline void DoubleLinkedList<T>::clear()
    {
        //TODO Zadanie 2: DoubleLinkedList
        throw std::runtime_error("DoubleLinkedList<T>::clear: Not implemented yet.");
    }

    template<typename T>
    inline Iterator<T>* DoubleLinkedList<T>::getBeginIterator()
    {
        //TODO Zadanie 2: DoubleLinkedList
        throw std::runtime_error("DoubleLinkedList<T>::getBeginIterator: Not implemented yet.");
    }

    template<typename T>
    inline Iterator<T>* DoubleLinkedList<T>::getEndIterator()
    {
        //TODO Zadanie 2: DoubleLinkedList
        throw std::runtime_error("DoubleLinkedList<T>::getEndIterator: Not implemented yet.");
    }
*/
    template<typename T>
    inline DoubleLinkedListItem<T>::DoubleLinkedListItem(T data) :
        DataItem<T>(data), next_(nullptr), previous_(nullptr)
    {
    }

    template<typename T>
    inline DoubleLinkedListItem<T>::DoubleLinkedListItem(DoubleLinkedListItem<T>& other) :
        DataItem<T>(other), next_(other.next_), previous_(other.previous_)
    {
    }

    template<typename T>
    inline DoubleLinkedListItem<T>::~DoubleLinkedListItem()
    {
        next_ = nullptr;
        previous_ = nullptr;
    }

    template<typename T>
    inline DoubleLinkedListItem<T>* DoubleLinkedListItem<T>::getPrevious()
    {
        return previous_;
    }

    template<typename T>
    inline void DoubleLinkedListItem<T>::setPrevious(DoubleLinkedListItem<T>* previous)
    {
        previous_ = previous;
    }

}