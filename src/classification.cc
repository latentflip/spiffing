/***

Copyright 2014-2015 Dave Cridland
Copyright 2014-2015 Surevine Ltd

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

***/

#include <spiffing/classification.h>
#include <spiffing/categorygroup.h>
#include <spiffing/categorydata.h>
#include <spiffing/marking.h>

using namespace Spiffing;

Classification::Classification(lacv_t lacv, std::string const & name, unsigned long hierarchy, bool obsolete)
: m_lacv{lacv}, m_name{name}, m_hierarchy{hierarchy}, m_obsolete{obsolete} {
}

bool Classification::operator < (Classification const & c) const {
	return m_hierarchy < c.m_hierarchy;
}

void Classification::compile(Spif const &) {
}

void Classification::addRequiredCategory(std::unique_ptr<CategoryGroup> reqCats) {
	m_reqCats.insert(std::move(reqCats));
}

void Classification::addMarking(std::unique_ptr<Marking> marking) {
	m_marking = std::move(marking);
}
