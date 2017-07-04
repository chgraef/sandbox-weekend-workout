# frozen_string_literal: true

require 'rspec'
require 'byebug'

require './california_sort_spec_helpers.rb'
require './california_sort.rb'

describe 'The Utils.california_sort method' do
  def described_method(*args)
    Utils.california_sort(*args)
  end

  it 'raises an ArgumentError if the array is nil' do
    expect { described_method(nil) }.to raise_error(ArgumentError)
  end

  it 'raises an ArgumentError if the array is not of type Array' do
    bad_params = ['', 0, 0.0, 0..9, {}].map(&:freeze).freeze
    bad_param  = bad_params.sample

    expect { described_method(bad_param) }.to raise_error(ArgumentError)
  end

  it 'raises an ArgumentError if the array contains a non-String item' do
    bad_ary = UtilsSpecHelpers.generate_array_with_non_string(1..31)

    expect { described_method(bad_ary) }.to raise_error(ArgumentError)
  end

  it 'raises an ArgumentError if a string contains non-alpha characters' do
    bad_ary = UtilsSpecHelpers.generate_array_with_bad_string(1..31)

    expect { described_method(bad_ary) }.to raise_error(ArgumentError)
  end

  it 'returns a sorted copy of the array according to the pre-defined order' do
    expected_order = 'RWQOJMVAHBSGZXNTCIEKUPDYFL'.split(//).freeze

    value_lookup = expected_order.zip(0...expected_order.size).to_h.freeze

    ary      = UtilsSpecHelpers.generate_good_array(15..25).freeze
    sorted   = Utils.california_sort(ary).freeze
    initials = sorted.map { |s| s[0, 1] }.freeze

    compares =
      initials.zip(initials[1..-1])[0...-1].map do |(prv, nxt)|
        # puts "Comparing: #{prv} and #{nxt}"
        value_lookup[prv.upcase] <= value_lookup[nxt.upcase]
      end.freeze

    is_in_order = compares.all?

    expect(is_in_order).to be_truthy
  end
end

